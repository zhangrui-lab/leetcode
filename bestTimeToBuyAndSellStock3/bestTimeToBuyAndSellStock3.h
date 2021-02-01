//
// Created by 张锐 on 2021/1/29.
//

#ifndef ALGORITHM_bestTimeToBuyAndSellStock31_H
#define ALGORITHM_bestTimeToBuyAndSellStock31_H

/*
 * 123. 买卖股票的最佳时机 III
 *  给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 *  设计一个算法来计算你所能获取的最大利润。你最多可以完成两笔交易。
 *  注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 * 1. DFS 探索所有可能的情况
 * 2. 动态规划
 *  buy1[i] 第 i 天内买入1次股票的最大收益
 *  sel1[i] 第 i 天内卖出1次股票的最大收益
 *  buy2[i] 第 i 天内买入2次股票的最大收益
 *  sel2[i] 第 i 天内卖出2次股票的最大收益
 *  buy1[i] = std::max(buy1[i-1], -prices[i]);  // 0～i-1买入 or 第 i 天买入
 *  sel1[i] = std::max(sel1[i-1], buy1[i-1] + prices[i]);
 *  buy2[i] = std::max(buy2[i-1], sel[1]-prices[i]);  // 0～i-1 已买入 or 第 i 天买入
 *  sel2[i] = std::max(sel2[i-1], buy2[i-1] + prices[i]);
 */

#include <vector>

void bestTimeToBuyAndSellStock31(int num, int day, int buyDay, int sum, std::vector<int> &prices, int &maximum) {
    if (num <= 2) {
        maximum = std::max(sum, maximum);
    }
    if (day == prices.size()) {
        return;
    }
    for (int i = day; i < prices.size(); ++i) {
        // 卖出
        if (buyDay >= 0) {
            bestTimeToBuyAndSellStock31(num + 1, i + 1, -1, sum + prices[i] - prices[buyDay], prices, maximum);
        } else {    // 买入
            bestTimeToBuyAndSellStock31(num, i + 1, i, sum, prices, maximum);
        }
    }
}

int bestTimeToBuyAndSellStock31(std::vector<int> &prices) {
    int maximum = INT_MIN;
    bestTimeToBuyAndSellStock31(0, 0, -1, 0, prices, maximum);
    return maximum;
}


int bestTimeToBuyAndSellStock32(std::vector<int> &prices) {
    if (prices.empty())
        return 0;
    int buy1 = -prices[0], sel1 = 0;
    int buy2 = -prices[0], sel2 = 0;
    for (int i = 1; i < prices.size(); ++i) {
        buy1 = std::max(buy1, -prices[i]);
        sel1 = std::max(sel1, buy1 + prices[i]);
        buy2 = std::max(buy2, sel1 - prices[i]);
        sel2 = std::max(sel2, buy2 + prices[i]);
    }
    return std::max(sel1, sel2);
}


#endif //ALGORITHM_bestTimeToBuyAndSellStock31_H
