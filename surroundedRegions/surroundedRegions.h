//
// Created by 张锐 on 2021/2/4.
//

#ifndef ALGORITHM_SURROUNDEDREGIONS_H
#define ALGORITHM_SURROUNDEDREGIONS_H

/*
 * 130. 被围绕的区域
 *  给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 *  找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * eg
 *  X X X X
 *  X O O X
 *  X X O X
 *  X O X X
 * =>
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 * 1. DFS
 *  获取所有边界上的 'O' 的坐标。 从边界上的 'O' 进行深度优先访问(存在 'O' 相邻则可达)，所有被访问到的节点皆不可被填充.
 * 2. BFS
 *  获取所有边界上的 'O' 为初始节点执行 BFS 访问， 存在相邻 'O' 表示可达，所有被访问到的节点皆不可被填充.
 */

#include <vector>
#include <unordered_set>
#include <utility>
#include <queue>

void surroundedRegions1(int i, int j, std::vector<std::vector<char>> &board) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')
        return;
    board[i][j] = 'A';
    surroundedRegions1(i + 1, j, board);
    surroundedRegions1(i - 1, j, board);
    surroundedRegions1(i, j + 1, board);
    surroundedRegions1(i, j - 1, board);
}


void surroundedRegions1(std::vector<std::vector<char>> &board) {
    if (board.empty() || board[0].empty())
        return;
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; ++i) {
        surroundedRegions1(i, 0, board);            // 第一列
        surroundedRegions1(i, m - 1, board);        // 最后一列
    }
    for (int i = 1; i < m - 1; ++i) {
        surroundedRegions1(0, i, board);            // 第一行
        surroundedRegions1(n - 1, i, board);        // 最后一行
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            board[i][j] = board[i][j] == 'A' ? 'O' : (board[i][j] == 'O' ? 'X' : board[i][j]);
        }
    }
}

#endif //ALGORITHM_SURROUNDEDREGIONS_H
