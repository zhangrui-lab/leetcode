//
// Created by 张锐 on 2021/1/15.
//

#ifndef ALGORITHM_SOLVESUDOKU_H
#define ALGORITHM_SOLVESUDOKU_H

/*
 * 解数独
 *  编写一个程序，通过填充空格来解决数独问题。
 *
 * 对于给定的一个数独。我们可以在O(n^2)的时间内判断其是否为合法数独。
 *
 * 深度优先策略遍历每个位置的所有可能值，获取当前数独的所有可能剩余组合。
 *
 * 剪枝回溯策略:
 *  维护每行没列每块的可插入字符数。
 *  每次迭代深入下一位置时，从可能的值中选择选择最小者。并将该值从当前位置所在行，列，块中移除。并继续深入。
 *  若当前深入位置不存在可值，则回溯。
 *  若当前位置为可尝试最后位置，则此数独为一个合法的解。
 *
 * 内存优化策略：位运算替代布尔矩阵。
 * 递归优化策略：如果一个空白格只有唯一的数可以填入，我们可以直接对其进行填入而非对其进行递归。
 */




#define SUDOKU_SIZE 9

#include <vector>
#include <utility>
#include <cassert>

bool rows[SUDOKU_SIZE][9];
bool columns[SUDOKU_SIZE][9];
bool block[SUDOKU_SIZE][9];

std::vector<char> allowNums(size_t r, size_t c) {
    std::vector<char> nums;
    for (int i = 0; i < 9; ++i)
        if (!rows[r][i] && !columns[c][i] && !block[r / 3 * 3 + c / 3][i])
            nums.push_back('1' + i);
    return nums;
}

// 设置在位置board[r][c]上的数值使用状态
void setNum(size_t r, size_t c, char num, bool used) {
    int n = num - '1';
    rows[r][n] = used;
    columns[c][n] = used;
    block[r / 3 * 3 + c / 3][n] = used;
}

void solveSudoku(std::vector<std::pair<int, int>> &notSetLocal, std::vector<std::vector<char>> &board, size_t pos, bool &solved) {
    if (pos == notSetLocal.size() || solved) {    // 成功
        solved = true;
        return;
    }
    size_t i = notSetLocal[pos].first;
    size_t j = notSetLocal[pos].second;
    std::vector<char> nums = allowNums(i, j);
    if (nums.empty())
        return;
    for (int k = 0; k < nums.size(); ++k) {
        board[i][j] = nums[k];
        setNum(i, j, nums[k], true);
        solveSudoku(notSetLocal, board, pos + 1, solved);
        if (solved) {
            return;
        }
        board[i][j] = '.';
        setNum(i, j, nums[k], false);
    }
}

void solveSudoku(std::vector<std::vector<char>> &board) {
    for (int i = 0; i < SUDOKU_SIZE; i++)
        for (int j = 0; j < 9; j++) {
            rows[i][j] = false;
            columns[i][j] = false;
            block[i][j] = false;
        }
    bool valid = true, solved = false;
    std::vector<std::pair<int, int>> notSetLocal;
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            if (board[i][j] == '.') {
                notSetLocal.push_back({i, j});
                continue;
            }
            int num = board[i][j] - '1', index = i / 3 * 3 + j / 3;
            if (rows[i][num] || columns[j][num] || block[index][num])
                valid = false;
            rows[i][num] = columns[j][num] = block[index][num] = true;
        }
    }
    assert(valid);
    solveSudoku(notSetLocal, board, 0, solved);
}

#endif //ALGORITHM_SOLVESUDOKU_H
