//
// Created by 张锐 on 2021/1/19.
//

#ifndef ALGORITHM_GENERATEMATRIX_H
#define ALGORITHM_GENERATEMATRIX_H

/*
 * 螺旋矩阵 II
 *  给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 *
 *  通过l,r,t,b界定生成的螺旋矩阵的边界。在生矩阵的过程中不断缩减边界,知道插入n^2个元素。
 *      上边界: for i=l to r: insert[t][i]; t++;
 *      右边界: for i=t to b: insert[i][r]; r--;
 *      下边界: for i=r to l: insert[b][i]; b--;
 *      左边界: for i=b to t: insert[i][l]; l++;
 *        t
 *   |-----------|
 *   |           |
 * l |           |  r
 *   |___________|
 *        b
 */


#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
    int num = 1, max = n*n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    int l = 0, t = 0, b = n - 1, r = n - 1;
    while (num <= max) {
        for (int i = l; i <= r; i++) { matrix[t][i] = num++; }
        t++;
        for (int i = t; i <= b; i++) { matrix[i][r] = num++; }
        r--;
        for (int i = r; i >= l; i--) { matrix[b][i] = num++; }
        b--;
        for (int i = b; i >= t; i--) { matrix[i][l] = num++; }
        l++;
    }
    return matrix;
}

#endif //ALGORITHM_GENERATEMATRIX_H
