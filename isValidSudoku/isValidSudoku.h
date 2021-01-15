//
// Created by 张锐 on 2021/1/15.
//

#ifndef ALGORITHM_ISVALIDSUDOKU_H
#define ALGORITHM_ISVALIDSUDOKU_H

#include <vector>
#include <unordered_set>

/*
 * 有效的数独
 *
 * 遍历数组，判断每个字符是否合法
 *  num 位于第 i 行，第 j 列， 第 (i/3)*3+j/3个块中。
 *  每个数字在所属行，所属列，所属块中均不可重复出现即可。
 *
 * 优化: 将元素记录的二维数组替换为布尔矩阵。
 */

bool isValidSudoku(std::vector<std::vector<char>> &board) {
    std::unordered_map<char, int> row[9], column[9], sub[9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] != '.' &&
                (row[i][board[i][j]]++ || column[j][board[i][j]]++ || sub[i / 3 * 3 + j / 3][board[i][j]]++))
                return false;
    return true;
}

void init(bool **matrix, size_t n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = false;
        }
    }
}

bool isValidSudoku1(std::vector<std::vector<char>> &board) {
    bool rows[board.size()][10], columns[board.size()][10], sub[board.size()][10];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 10; j++) {
            rows[i][j] = false;
            columns[i][j] = false;
            sub[i][j] = false;
        }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == '.')
                continue;
            int num = board[i][j] - '0', index = i / 3 * 3 + j / 3;
            if (rows[i][num] || columns[j][num] || sub[index][num])
                return false;
            rows[i][num] = columns[j][num] = sub[index][num] = true;
        }
    }
    return true;
}

#endif //ALGORITHM_ISVALIDSUDOKU_H
