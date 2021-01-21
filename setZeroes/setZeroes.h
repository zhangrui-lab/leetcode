//
// Created by 张锐 on 2021/1/21.
//

#ifndef ALGORITHM_SETZEROES_H
#define ALGORITHM_SETZEROES_H

/*
 * 73. 矩阵置零
 *  给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 *
 *  1. 使用map/vector等额外的数据结构记录需要置0的行/列。
 *  2. 标记行的第一个元素和列的第一个元素来表示当前行/列需要置0。(需要区分第一行和第一列)
 *  3. 使用两个整数，用位操作来表示需要置0的行和列。
 */

#include <vector>
#include <unordered_set>

void setZeroes1(std::vector<std::vector<int>> &matrix) {
    std::unordered_set<int> rows;
    std::unordered_set<int> columns;
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j < matrix[i].size(); ++j)
            if (matrix[i][j] == 0) {
                rows.insert(i);
                columns.insert(j);
            }
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j < matrix[i].size(); ++j)
            if (rows.find(i) != rows.cend() || columns.find(j) != columns.cend())
                matrix[i][j] = 0;
}


void setZeroes2(std::vector<std::vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return;
    int n = matrix.size(), m = matrix[0].size();
    long long rows = 1 << n, columns = 1 << m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (matrix[i][j] == 0) {
                rows |= (1 << i);
                columns |= (1 << j);
            }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (rows & (1 << i) || columns & (1 << j))
                matrix[i][j] = 0;
}

void setZeroes3(std::vector<std::vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    int indR = -1, indC = -1, flag = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                if (flag) {
                    indR = i;
                    indC = j;
                    flag = 0;
                } else {
                    matrix[indR][j] = 0;
                    matrix[i][indC] = 0;
                }
            }
        }
    }
    if (indR == -1) return;
    for (int i = 0; i < row; i++) {
        if (i == indR) continue;
        if (matrix[i][indC] == 0) {
            for (int j = 0; j < col; j++) matrix[i][j] = 0;
        } else matrix[i][indC] = 0;
    }
    for (int j = 0; j < col; j++) {
        if (j == indC) continue;
        if (matrix[indR][j] == 0) {
            for (int i = 0; i < row; i++) matrix[i][j] = 0;
        } else matrix[indR][j] = 0;
    }
}

#endif //ALGORITHM_SETZEROES_H
