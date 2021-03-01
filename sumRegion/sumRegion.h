//
// Created by 张锐 on 2021/3/1.
//

#ifndef ALGORITHM_SUMREGION_H
#define ALGORITHM_SUMREGION_H

/*
 * 304. 二维区域和检索 - 矩阵不可变
 *  给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。
 *
 * 一维前缀和
 *  sumRegion(r1, c1, r2, c2):
 *      sum = 0;
 *      for r=r1 to t2:
 *          sum+=sumRange(r2, c2);
 *
 * 二维前缀和
 *  sMatrix[i][j] = sumRegion(0, 0, i, j);
 *  sumRegion(r1, c1, r2, c2):
 *      sMatrix[r2][c2] - sMatrix[r1-1][c2] - sMatrix[r2][c1-1] + sMatrix[r1-1][c1-1];
 */

#include <vector>
#include "../sumRange/sumRange.h"

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> sMatrix;
    vector<vector<int>> matrix;

    NumMatrix(vector<vector<int>> &matrix) : matrix(matrix), sMatrix(matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                sMatrix[i][j] =
                        (i - 1 >= 0 ? sMatrix[i - 1][j] : 0) + (j - 1 >= 0 ? sMatrix[i][j - 1] : 0) + matrix[i][j] -
                        (i - 1 >= 0 && j - 1 >= 0 ? sMatrix[i - 1][j - 1] : 0);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sMatrix[row2][col2] - (row1 - 1 >= 0 ? sMatrix[row1 - 1][col2] : 0) -
               (col1 - 1 >= 0 ? sMatrix[row2][col1 - 1] : 0) +
               (row1 - 1 >= 0 && col1 - 1 >= 0 ? sMatrix[row1 - 1][col1 - 1] : 0);
    }
};

class NumMatrix1 {
public:
    vector<vector<int>> sMatrix;
    vector<vector<int>> matrix;

    NumMatrix1(vector<vector<int>> &matrix) : matrix(matrix), sMatrix(matrix.size(),
                                                                      vector<int>(matrix.empty() ? 0 : matrix[0].size(),
                                                                                  0)) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int k = 1; k < matrix[i].size(); ++k)
                sMatrix[i][k] = sMatrix[i][k - 1] + matrix[i][k - 1];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            if (row1 <= i && i <= row2)
                sum += sMatrix[i][col2] - sMatrix[i][col1] + matrix[i][col2];
        }
        return sum;
    }
};

#endif //ALGORITHM_SUMREGION_H
