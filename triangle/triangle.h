//
// Created by 张锐 on 2021/1/28.
//

#ifndef ALGORITHM_TRIANGLE_H
#define ALGORITHM_TRIANGLE_H

/*
 * 120. 三角形最小路径和
 *  给定一个三角形 triangle ，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。相邻的结点在这里指的是下标与上一层结点下标相同
 *  或者等于上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
 *
 * 1. DFS
 * 2. 动态规划
 *  用 f[i][j] 表示从三角形顶部走到位置(i,j) 的最小路径和。这里的位置(i,j) 指的是三角形中第i行第j列(均从 0 开始编号）的位置。
 *  f[i][j]=min(f[i−1][j−1],f[i−1][j])+c[i][j]；
 *  f[i][0]=f[i−1][0]+c[i][0]
 *  f[i][i]=f[i−1][i−1]+c[i][i]
 *  f[0][0]=c[0][0]
 * 3. 滚动数组进行空间复杂度优化
 * 4. 进一步优化空间复杂度
 */

#include <vector>
#include <algorithm>

void minimumTotal(int l, int p, int sum, std::vector<std::vector<int>> &triangle, int &minimum) {
    if (l == triangle.size()) {
        minimum = std::min(minimum, sum);
        return;
    }
    if (p >= triangle[l].size())
        return;
    minimumTotal(l + 1, p, sum + triangle[l][p], triangle, minimum);
    minimumTotal(l + 1, p + 1, sum + triangle[l][p], triangle, minimum);
}

int minimumTotal(std::vector<std::vector<int>> &triangle) {
    int minimum = INT_MAX;
    minimumTotal(0, 0, 0, triangle, minimum);
    return minimum;
}

int minimumTotal2(std::vector<std::vector<int>> &triangle) {
    int n = triangle.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    return *std::min_element(dp[n - 1].begin(), dp[n - 1].end());
}

int minimumTotal3(std::vector<std::vector<int>> &triangle) {
    int n = triangle.size();
    std::vector<std::vector<int>> dp(2, std::vector<int>(n));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
        int curr = i % 2, prev = 1 - curr;
        dp[curr][0] = dp[prev][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            dp[curr][j] = std::min(dp[prev][j - 1], dp[prev][j]) + triangle[i][j];
        }
        dp[curr][i] = dp[prev][i - 1] + triangle[i][i];
    }
    return *std::min_element(dp[(n - 1) % 2].begin(), dp[(n - 1) % 2].end());
}

/* [[2],[3,4],[6,5,7],[4,1,8,3]]
 * 0:      2
 * 1:     3 4
 * 2:    6 5 7
 * 3:   4 1 8 3
 *
 * i-1: [x, x, x ]
 *       | \| \| \
 * i :  [x, x, x, x]
 * dp[i][j] = min(dp[i-][j], dp[i-1][j-1]) + c[i][j]; j=0;
 */
int minimumTotal4(std::vector<std::vector<int>> &triangle) {
    int n = triangle.size();
    std::vector<int> dp(n);
    dp[0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] + triangle[i][i];
        for (int j = i - 1; j > 0; --j) {
            dp[j] = std::min(dp[j - 1], dp[j]) + triangle[i][j];
        }
        dp[0] += triangle[i][0];
    }
    return *std::min_element(dp.begin(), dp.end());
}

#endif //ALGORITHM_TRIANGLE_H
