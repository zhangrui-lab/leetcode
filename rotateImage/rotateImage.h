//
// Created by 张锐 on 2021/1/18.
//

#ifndef ALGORITHM_ROTATEIMAGE_H
#define ALGORITHM_ROTATEIMAGE_H

/*
 * 旋转图像
 *  你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 *  给定 matrix =
 *  [
 *      [1,2,3],
 *      [4,5,6],
 *      [7,8,9]
 *  ],
 *  原地旋转输入矩阵，使其变为:
 *  [
 *      [7,4,1],
 *      [8,5,2],
 *      [9,6,3]
 *  ]
 *
 * 1. 使用辅助数组，将元素的第i行变成为第 matrix.size - 1 - i 列。元素第 j 列放置在第 j 行（倒序）。
 *      rotate[col][n−row−1]=matrix[row][col]
 * 2. 不使用辅助数组，交换元素，使元素就位。
 *     [i][j] => [j][n-1-i]
 *     [j][n-1-i] => [n-1-i][n-1-j]
 *     [n-1-i][n-1-j] => [n-1-j][i]
 *     [n-1-j][i] => [i][j]
 * 3. 用翻转代替旋转
 *      [1,2,3],     水平翻转       [7, 8, 9],     对角线翻转     [7,4,1],
 *      [4,5,6],   =========》     [4, 5, 6],   ===========>   [8,5,2],
 *      [7,8,9]                    [1, 2, 3],                  [9,6,3],
 *  水平翻转:   flip1[n-1-i][j] = matrix[i][j];
 *  对角线翻转: flip1[j][i] = flip1[i][j];
 */

#include <vector>

void rotateImage(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    std::vector<std::vector<int>> output(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            output[j][n - 1 - i] = matrix[i][j];
        }
    }
    matrix = output;
}


void rotateImage1(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < (n + 1) / 2; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = tmp;
        }
    }
}

void rotateImage2(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i)
        for (int j = 0; j < n; ++j)
            std::swap(matrix[n - 1 - i][j], matrix[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            std::swap(matrix[j][i], matrix[i][j]);
}


#endif //ALGORITHM_ROTATEIMAGE_H
