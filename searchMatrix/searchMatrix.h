//
// Created by 张锐 on 2021/1/21.
//

#ifndef ALGORITHM_SEARCHMATRIX_H
#define ALGORITHM_SEARCHMATRIX_H

/*
 * 74. 搜索二维矩阵
 *  编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。
 *  该矩阵具有如下特性：每行中的整数从左到右按升序排列。每行的第一个整数大于前一行的最后一个整数。
 *
 * 在 0 ~ matrix.size() 中执行二分搜索。
 *  pos 为位置 matrix[pos/n][pos%n]
 */


bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
        return false;
    int n = matrix.size(), m = matrix[0].size(), lo = 0, hi = m * n, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        printf("mid=%d, matrix[%d][%d]=%d\n", mid, mid / m, mid % m, matrix[mid / m][mid % m]);
        if (matrix[mid / m][mid % m] <= target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo - 1 < 0 ? false : matrix[(lo - 1) / m][(lo - 1) % m] == target ? true : false;
}

#endif //ALGORITHM_SEARCHMATRIX_H
