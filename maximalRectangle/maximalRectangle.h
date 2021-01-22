//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_MAXIMALRECTANGLE_H
#define ALGORITHM_MAXIMALRECTANGLE_H

/*
 * 85. 最大矩形
 *  给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 */

#include <vector>

#include "../largestRectangleArea/largestRectangleArea.h"

int maximalRectangle(std::vector<std::vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
        return 0;
    int largest = 0, n = matrix.size(), m = matrix[0].size();
    std::vector<int> prev(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            prev[j] = (matrix[i][j] - '0') == 0 ? 0 : prev[j] + (matrix[i][j] - '0');
        }
        largest = std::max(largest, largestRectangleArea4(prev));
    }
    return largest;
}

#endif //ALGORITHM_MAXIMALRECTANGLE_H
