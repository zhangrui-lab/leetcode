//
// Created by 张锐 on 2021/1/19.
//

#ifndef ALGORITHM_UNIQUEPATHS_H
#define ALGORITHM_UNIQUEPATHS_H

/*
 * 不同路径
 *  一个机器人位于一个 m x n 网格的左上角 （起始点标记为 “Start” ）。机器人每次只能向下或者向右移动一步。 机器人试图达到网格的右下角（标记为 “Finish” ）。问总共有多少条不同的路径？
 *
 * DFS遍历并统计所有可能的情况
 *
 * 动态规划:
 *  令dp[i][j]为从Start当当前位置的不同路径数。则原问题的解为dp[m-1][n-1]。
 *  dp[i][j] = dp[i-1][j]+dp[i][j-1];   (i != 0 && j != 0)
 *           = 1;                       (i == 0 || j == 0)
 *
 * 滚动数组策略优化动态规划
 *  dp[i][j]只会使用到dp[i-1][j], dp[i][j-1]。 故dp数组可以只保存当前行和上一行的数据信息。
 *
 *
 * 组合数学求解
 *  机器人每次只能向下或者向右移动一步， 故想从(0, 0)到达(m-1, n-1)需要向下m-1步，向右n-1步。总共需要走m+n-2步。求解可能的走法为求m+n-2中m-1的组合。
 */

#include <vector>

int uniquePaths1(int m, int n) {
    if (m <= 0 || n <= 0)
        return 0;
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i)     //  第一列
        dp[i][0] = 1;
    for (int i = 0; i < n; ++i)     //  第一行
        dp[0][i] = 1;
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int uniquePaths2(int m, int n) {
    long long ans = 1;
    for (int x = n, y = 1; y < m; ++x, ++y) {
        ans = ans * x / y;
    }
    return ans;
}

void uniquePaths3(int m, int n, int r, int c, int &ans) {
    if (r >= m || c >= n)
        return;
    if (r == m - 1 && c == n - 1) {
        ans++;
        return;
    }
    uniquePaths3(m, n, r, c+1, ans);
    uniquePaths3(m, n, r+1, c, ans);
}

int uniquePaths3(int m, int n) {
    int ans = 0;
    uniquePaths3(m, n, 0, 0, ans);
    return ans;
}

// DFS遍历并统计所有可能的情况

#endif //ALGORITHM_UNIQUEPATHS_H
