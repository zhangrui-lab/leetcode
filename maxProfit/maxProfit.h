//
// Created by 张锐 on 2021/3/1.
//

#ifndef ALGORITHM_MAXPROFIT_H
#define ALGORITHM_MAXPROFIT_H


/*
 * 309. 最佳买卖股票时机含冷冻期
 *  给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
 *  设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 *  你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *  卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 *
 * DFS求解
 * 动态规划
 *  dp[i][0] 第i天后手上有股票时的最大收益
 *  dp[i][1] 第i天后手上没有股票且在冷冻期时的最大收益
 *  dp[i][2] 第i天后手上没有股票且不在冷冻期时的最大收益
 * dp[i] 均可由 dp[i-1]状态转移而来:
 *  dp[i][0] = max(dp[i-1][0], dp[i][2] - prices[i])
 *  dp[i][1] = dp[i-1][0] + prices[i]
 *  dp[i][2] = max(dp[i-1][1], dp[i-1][2])
 * 动态规划空间优化
 *  dp[i][0/1/2] 只依赖于 dp[i-1][0/1/2] 三个数
 */

#include <vector>

void maxProfit(std::vector<int> &prices, int day, int buyDay, int sum, int &max) {
    if (day >= prices.size()) {
        max = std::max(max, sum);
        return;
    }
    // 今天执行 买入/卖出 操作
    if (buyDay != -1) {     // 卖出
        maxProfit(prices, day + 2, -1, sum + prices[day] - prices[buyDay], max);
    } else {                // 买入
        maxProfit(prices, day + 1, day, sum, max);
    }
    // 今天不执行 买入/卖出 操作
    maxProfit(prices, day + 1, buyDay, sum, max);
}

int maxProfit(std::vector<int> &prices) {
    int max = INT_MIN;
    maxProfit(prices, 0, -1, 0, max);
    return max;
}

int maxProfit1(std::vector<int> &prices) {
    if (prices.empty())
        return 0;
    int n = prices.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
        dp[i][1] = dp[i - 1][0] + prices[i];
        dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]);
    }
    return std::max(dp[n - 1][1], dp[n - 1][2]);
}

int maxProfit2(std::vector<int> &prices) {
    if (prices.empty())
        return 0;
    int n = prices.size();
    int dp0 = -prices[0], dp1 = 0, dp2 = 0;
    int cur0, cur1, cur2;
    for (int i = 1; i < n; ++i) {
        cur0 = std::max(dp0, dp2 - prices[i]);
        cur1 = dp0 + prices[i];
        cur2 = std::max(dp1, dp2);
        dp0 = cur0;
        dp1 = cur1;
        dp2 = cur2;
    }
    return std::max(dp1, dp2);
}

#endif //ALGORITHM_MAXPROFIT_H
