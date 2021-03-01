//
// Created by 张锐 on 2021/3/1.
//

#ifndef ALGORITHM_DIAGONALSUM_H
#define ALGORITHM_DIAGONALSUM_H

/*
 * 1572. 矩阵对角线元素的和
 *  给你一个正方形矩阵 mat，请你返回矩阵对角线元素的和。
 *  请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。
 */

#include <vector>

int diagonalSum(std::vector<std::vector<int>> &mat) {
    if (mat.empty())
        return 0;
    int n = mat.size();
    int sum = n % 2 ? -mat[n / 2][n / 2] : 0;
    for (int i = 0; i < n; ++i) {
        sum += mat[i][i] + mat[i][n - i - 1];
    }
    return sum;
}

#endif //ALGORITHM_DIAGONALSUM_H
