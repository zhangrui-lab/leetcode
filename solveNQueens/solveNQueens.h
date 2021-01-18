//
// Created by 张锐 on 2021/1/18.
//

#ifndef ALGORITHM_SOLVENQUEENS_H
#define ALGORITHM_SOLVENQUEENS_H

/*
 * N 皇后
 *  n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *  给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 * DFS深度优先
 *  matrix = [
 *      (0,0) (0,1) (0,2) (0,3)
 *      (1,0) (1,1) (1,2) (1,3)
 *      (2,0) (2,1) (2,2) (2,3)
 *      (3,0) (3,1) (2,2) (3,3)
 *  ]
 * 剪枝回溯策略:
 *  matrix[i][j] = 第i行存在其他皇后时回溯
 *               = 第j列存在其他皇后时回溯
 *               = 位置 i`+j` == i+j 的位置能存在皇后时回溯
 *               = 位置 [i+x][j+x]的位置能存在皇后时回溯([i+x][j+x]合法时)
 *               = 位置 [i-x][j-x]的位置能存在皇后时回溯([i-x][j-x]合法时)
 *
 * 优化策略: 使用O(1)的时间复杂度去验证是否应该回溯。
 *  1. 列，斜线(正/反)的hash表。
 *  2. 使用三个整数替换三个hash表，用位运算实现。
 */

#include <vector>
#include <string>
#include <unordered_set>

bool canPut(const std::vector<std::string> &curr, int n, int i, int j) {
    for (int k = 0; k < n; ++k)
        if (curr[i][k] == 'Q' || curr[k][j] == 'Q' || (i - k >= 0 && j - k >= 0 && curr[i - k][j - k] == 'Q'))
            return false;
    for (int k = 0; k < i; ++k) {
        for (int l = 0; l < n; ++l) {
            if (l + k == i + j && curr[k][l] == 'Q')
                return false;
        }
    }
    return true;
}

void solveNQueens(int n, int p, std::vector<std::vector<std::string>> &ans, std::vector<std::string> &curr) {
    if (p == n) {
        ans.push_back(curr);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!canPut(curr, n, p, i))
            continue;
        curr[p][i] = 'Q';
        solveNQueens(n, p + 1, ans, curr);
        curr[p][i] = '.';
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> curr(n, std::string(n, '.'));
    solveNQueens(n, 0, ans, curr);
    return ans;
}


std::vector<std::string> generateBoard(std::vector<int> &queens, int n) {
    auto board = std::vector<std::string>();
    for (int i = 0; i < n; i++) {
        std::string row = std::string(n, '.');
        row[queens[i]] = 'Q';
        board.push_back(row);
    }
    return board;
}

void solveNQueensBacktrack(std::vector<std::vector<std::string>> &solutions, std::vector<int> &queens, int n, int row,
                           std::unordered_set<int> &columns, std::unordered_set<int> &diagonals1,
                           std::unordered_set<int> &diagonals2) {
    if (row == n) {
        std::vector<std::string> board = generateBoard(queens, n);
        solutions.push_back(board);
    } else {
        for (int i = 0; i < n; i++) {
            if (columns.find(i) != columns.end()) {
                continue;
            }
            int diagonal1 = row - i;
            if (diagonals1.find(diagonal1) != diagonals1.end()) {
                continue;
            }
            int diagonal2 = row + i;
            if (diagonals2.find(diagonal2) != diagonals2.end()) {
                continue;
            }
            queens[row] = i;
            columns.insert(i);
            diagonals1.insert(diagonal1);
            diagonals2.insert(diagonal2);
            solveNQueensBacktrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
            queens[row] = -1;
            columns.erase(i);
            diagonals1.erase(diagonal1);
            diagonals2.erase(diagonal2);
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens1(int n) {
    auto solutions = std::vector<std::vector<std::string>>();
    auto queens = std::vector<int>(n, -1);
    auto columns = std::unordered_set<int>();
    auto diagonals1 = std::unordered_set<int>();
    auto diagonals2 = std::unordered_set<int>();
    solveNQueensBacktrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
    return solutions;
}


std::vector<std::string> generateBoard2(std::vector<int> &queens, int n) {
    auto board = std::vector<std::string>();
    for (int i = 0; i < n; i++) {
        std::string row = std::string(n, '.');
        row[queens[i]] = 'Q';
        board.push_back(row);
    }
    return board;
}

void solve(std::vector<std::vector<std::string>> &solutions, std::vector<int> &queens, int n, int row, int columns,
           int diagonals1, int diagonals2) {
    if (row == n) {
        auto board = generateBoard2(queens, n);
        solutions.push_back(board);
    } else {
        int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
        while (availablePositions != 0) {
            int position = availablePositions & (-availablePositions);
            availablePositions = availablePositions & (availablePositions - 1);
            int column = __builtin_ctz(position);
            queens[row] = column;
            solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1,
                  (diagonals2 | position) << 1);
            queens[row] = -1;
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens2(int n) {
    auto solutions = std::vector<std::vector<std::string>>();
    auto queens = std::vector<int>(n, -1);
    solve(solutions, queens, n, 0, 0, 0, 0);
    return solutions;
}


#endif //ALGORITHM_SOLVENQUEENS_H
