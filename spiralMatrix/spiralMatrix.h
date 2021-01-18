//
// Created by 张锐 on 2021/1/18.
//

#ifndef ALGORITHM_SPIRALMATRIX_H
#define ALGORITHM_SPIRALMATRIX_H

/*
 * 螺旋矩阵
 *  给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 *  matrix = [
 *      (0,0) (0,1) (0,2)
 *      (1,0) (1,1) (1,2)
 *      (2,0) (2,1) (2,2)
 *      (3,0) (3,1) (3,2)
 *  ];
 *  resu => [ (0,0) (0,1) (0,2) (1,2) (2,2) (3,2) (3,1) (3,0) (2,0) (1,0) (1,1) (2,1)]
 */

#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return {};
    int rows = matrix.size(), columns = matrix[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns));
    int total = rows * columns;
    std::vector<int> order(total);
    int row = 0, column = 0;
    int directionIndex = 0;
    for (int i = 0; i < total; i++) {
        order[i] = matrix[row][column];
        visited[row][column] = true;
        int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
        if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
            directionIndex = (directionIndex + 1) % 4;
        }
        row += directions[directionIndex][0];
        column += directions[directionIndex][1];
    }
    return order;
}

#endif //ALGORITHM_SPIRALMATRIX_H
