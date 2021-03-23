//
// Created by 张锐 on 2021/3/23.
//

#ifndef ALGORITHM_UPDATEMATRIX_H
#define ALGORITHM_UPDATEMATRIX_H

/*
 * 542. 01 矩阵
 *  给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
 *  两个相邻元素间的距离为 1 。
 * eg:
 *  输入：[[0,0,0],[0,1,0],[0,0,0]]
 *  输出：[[0,0,0],[0,1,0],[0,0,0]]
 *
 * 1. DFS 深度优先算法
 *  任选一节点进行深度优先访问，没发现一个节点时，依据父节点更新其最近距离。节点访问完成时，更新其父节点最近距离。(该图结构为无向联通图，故在开始访问节点时新增更新子节点的步骤)
 * 2. BFS 广度优先算法
 *  对所有的 0 执行 BFS 算法。获取其他所有 1 到该 0 的最短距离，并获取到任意 0 的最短距离。
 *  将当前队列中的所有节点抽象为超级节点。（所有可达队列中任意节点的节点都为下一层节点）
 * 3. 动态规划
 *  对于矩阵中的任意一个 1 以及一个 0，我们如何从这个 1 到达 0 并且距离最短呢？根据上面的做法，我们可以从 1 开始，先在水平方向移动，直到与 0 在同一列，随后再在竖直方向上移动，直到到达 0 的位置。这样一来，从一个固定的 1 走到任意一个 00，在距离最短的前提下可能有四种方法：
 *  只有 水平向左移动 和 竖直向上移动；
 *      f(i,j)= 1+min(f(i−1,j),f(i,j−1)) ,位置 (i,j) 的元素为 1
 *            = 0                        ,位置 (i,j) 的元素为 0
 *  只有 水平向左移动 和 竖直向下移动；
 *      f(i,j)= 1+min(f(i+1,j),f(i,j−1)) ,位置 (i,j) 的元素为 1
 *            = 0                        ,位置 (i,j) 的元素为 0
 *  只有 水平向右移动 和 竖直向上移动；
 *      f(i,j)= 1+min(f(i−1,j),f(i,j+1)) ,位置 (i,j) 的元素为 1
 *            = 0                        ,位置 (i,j) 的元素为 0
 *  只有 水平向右移动 和 竖直向下移动。
 *      f(i,j)= 1+min(f(i+1,j),f(i,j+1)) ,位置 (i,j) 的元素为 1
 *            = 0                        ,位置 (i,j) 的元素为 0
 * 4. 动态规划优化
 */

#include <vector>
#include <queue>

void updateMatrix(int i, int j, std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &ans,
                  std::vector<std::vector<bool>> &visited) {
    static auto validIJ = [&matrix](int i, int j) {
        return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size();
    };
    if (!validIJ(i, j) || visited[i][j])
        return;
    visited[i][j] = true;
    if (matrix[i][j] == 0)
        ans[i][j] = 0;
    static auto updater = [&](int si, int sj, int ti, int tj) {
        if (!validIJ(si, sj) || !validIJ(ti, tj))
            return;
        if (ans[si][sj] < ans[ti][tj])
            ans[ti][tj] = ans[si][sj] + 1;
    };

    updater(i, j, i - 1, j);
    updater(i, j, i + 1, j);
    updater(i, j, i, j - 1);
    updater(i, j, i, j + 1);

    updateMatrix(i - 1, j, matrix, ans, visited);
    updater(i - 1, j, i, j);

    updateMatrix(i + 1, j, matrix, ans, visited);
    updater(i + 1, j, i, j);


    updateMatrix(i, j - 1, matrix, ans, visited);
    updater(i, j - 1, i, j);


    updateMatrix(i, j + 1, matrix, ans, visited);
    updater(i, j + 1, i, j);
}

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    if (!n)
        return {{}};
    std::vector<std::vector<int>> ans(n, std::vector<int>(matrix[0].size(), INT_MAX));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(matrix[0].size(), false));
    updateMatrix(0, 0, matrix, ans, visited);
    return ans;
}


std::vector<std::vector<int>> updateMatrix2(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    if (!n) return {{}};
    std::vector<std::vector<int>> ans(n, std::vector<int>(matrix[0].size(), -1));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(matrix[0].size(), false));
    std::queue<std::pair<int, int>> queue;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < matrix[i].size(); ++j)
            if (!matrix[i][j]) {
                visited[i][j] = true;
                queue.push({i, j});
            }
    auto validIJ = [&matrix](int i, int j) {
        return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size();
    };
    int dirI[] = {-1, 1, 0, 0};
    int dirJ[] = {0, 0, -1, 1};
    int depth = 0;
    while (!queue.empty()) {
        int sz = queue.size();
        for (int i = 0; i < sz; ++i) {
            std::pair<int, int> node = queue.front();
            queue.pop();
            for (int j = 0; j < 4; ++j) {
                int ni = node.first + dirI[j];
                int nj = node.second + dirJ[j];
                if (validIJ(ni, nj) && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    queue.push({ni, nj});
                }
            }
            ans[node.first][node.second] = depth;
        }
        depth++;
    }
    return ans;
}


std::vector<std::vector<int>> updateMatrix3(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    // 初始化动态规划的数组，所有的距离值都设置为一个很大的数
    std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX / 2));
    // 如果 (i, j) 的元素为 0，那么距离为 0
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }
    // 只有 水平向左移动 和 竖直向上移动，注意动态规划的计算顺序
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - 1 >= 0) {
                dist[i][j] = std::min(dist[i][j], dist[i - 1][j] + 1);
            }
            if (j - 1 >= 0) {
                dist[i][j] = std::min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }
    // 只有 水平向左移动 和 竖直向下移动，注意动态规划的计算顺序
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (i + 1 < m) {
                dist[i][j] = std::min(dist[i][j], dist[i + 1][j] + 1);
            }
            if (j - 1 >= 0) {
                dist[i][j] = std::min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }
    // 只有 水平向右移动 和 竖直向上移动，注意动态规划的计算顺序
    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i - 1 >= 0) {
                dist[i][j] = std::min(dist[i][j], dist[i - 1][j] + 1);
            }
            if (j + 1 < n) {
                dist[i][j] = std::min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
    }
    // 只有 水平向右移动 和 竖直向下移动，注意动态规划的计算顺序
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i + 1 < m) {
                dist[i][j] = std::min(dist[i][j], dist[i + 1][j] + 1);
            }
            if (j + 1 < n) {
                dist[i][j] = std::min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
    }
    return dist;
}


std::vector<std::vector<int>> updateMatrix4(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    // 初始化动态规划的数组，所有的距离值都设置为一个很大的数
    std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX / 2));
    // 如果 (i, j) 的元素为 0，那么距离为 0
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }
    // 只有 水平向左移动 和 竖直向上移动，注意动态规划的计算顺序
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - 1 >= 0) {
                dist[i][j] = std::min(dist[i][j], dist[i - 1][j] + 1);
            }
            if (j - 1 >= 0) {
                dist[i][j] = std::min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }
    // 只有 水平向右移动 和 竖直向下移动，注意动态规划的计算顺序
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i + 1 < m) {
                dist[i][j] = std::min(dist[i][j], dist[i + 1][j] + 1);
            }
            if (j + 1 < n) {
                dist[i][j] = std::min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
    }
    return dist;
}

#endif //ALGORITHM_UPDATEMATRIX_H
