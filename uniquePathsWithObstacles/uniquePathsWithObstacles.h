//
// Created by 张锐 on 2021/1/20.
//

#ifndef ALGORITHM_UNIQUEPATHSWITHOBSTACLES_H
#define ALGORITHM_UNIQUEPATHSWITHOBSTACLES_H

/*
 * 不同路径 II
 *  一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。机器人每次只能向下或者向右移动一步。机器人试图达到网
 *  格的右下角（在下图中标记为“Finish”）。现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 *
 * 动态规划:(在不同路径的基础上加上特殊情况)
 *  dp[i][j] = dp[i-1][j]+dp[i][j-1];    (obstacleGrid[i][j] == 0 && i > 0 && j > 0)
 *           = 1;                        (obstacleGrid[i][j] == 0 && (i == 0 || j == 0))
 *           = 0;                        (obstacleGrid[i][j])
 *
 * DFS深度优先访问
 */

#include <vector>

// 动态规划
int uniquePathsWithObstacles1(std::vector<std::vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (m <= 0 || n <= 0)
        return 0;
    if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
        return 0;
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i)     //  第一列
        dp[i][0] = obstacleGrid[i][0] || (i > 0 && !dp[i - 1][0]) ? 0 : 1;
    for (int i = 0; i < n; ++i)     //  第一行
        dp[0][i] = obstacleGrid[0][i] || (i > 0 && !dp[0][i - 1]) ? 0 : 1;
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = obstacleGrid[i][j] ? 0 : (dp[i - 1][j] + dp[i][j - 1]);
        }
    }
    return dp[m - 1][n - 1];
}

//DFS
void uniquePathsWithObstacles2(std::vector<std::vector<int>> &obstacleGrid, int r, int c, int &ans) {
    if (obstacleGrid.empty() || obstacleGrid[0].empty() || r >= obstacleGrid.size() || c >= obstacleGrid[0].size() || obstacleGrid[r][c])
        return;
    if (r == obstacleGrid.size() - 1 && c == obstacleGrid[0].size() - 1) {
        ans++;
        return;
    }
    uniquePathsWithObstacles2(obstacleGrid, r + 1, c, ans);
    uniquePathsWithObstacles2(obstacleGrid, r, c + 1, ans);
}
int uniquePathsWithObstacles2(std::vector<std::vector<int>> &obstacleGrid) {
    int ans = 0;
    uniquePathsWithObstacles2(obstacleGrid, 0, 0, ans);
    return ans;
}

#endif //ALGORITHM_UNIQUEPATHSWITHOBSTACLES_H
