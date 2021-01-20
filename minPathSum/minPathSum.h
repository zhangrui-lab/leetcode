//
// Created by 张锐 on 2021/1/20.
//

#ifndef ALGORITHM_MINPATHSUM_H
#define ALGORITHM_MINPATHSUM_H

/*
 * 最小路径和
 *  给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *  说明：每次只能向下或者向右移动一步。
 *
 * 动态规划:
 *  dp[i][j] 为从 grid[0][0] 到 grid[i][j] 的最小距离。
 *  最小路径和的解为 dp[m][n];
 *  dp[i][j] = dp[i-1][0]+grid[i][0];                           (j==0)
 *           = dp[0][j-1]+grid[0][j];                           (i==0)
 *           = min( dp[i-1][j], dp[i][j-1] ) + grid[i][j];   (i>0 || j>0)
 */

#include <vector>

int minPathSum(std::vector<std::vector<int>> &grid) {
    if (grid.empty() || grid[0].empty())
        return 0;
    int n = grid.size(), m = grid[0].size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(m));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; ++i)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int i = 1; i < m; ++i)
        dp[0][i] = dp[0][i-1] + grid[0][i];
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    for (int k = 0; k < dp.size(); ++k) {
        for (int i = 0; i < dp[k].size(); ++i) {
            printf("%d ", dp[k][i]);
        }
        printf("\n");
    }
    return dp[n-1][m-1];
}

#endif //ALGORITHM_MINPATHSUM_H
