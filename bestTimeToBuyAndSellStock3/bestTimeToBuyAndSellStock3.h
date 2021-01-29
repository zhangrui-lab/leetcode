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
 */

#include <vector>

void bestTimeToBuyAndSellStock31(int num, int day, int buyDay, int sum, std::vector<int> &prices, int &ans) {
    if (num == 2) {
        ans = std::max(sum, ans);
        return;
    }
    if (day == prices.size()) {
        return;
    }
    for (int i = day; i < prices.size(); ++i) {
        if (buyDay >= 0) {
            bestTimeToBuyAndSellStock21(i + 1, -1, sum + prices[i] - prices[buyDay], prices, ans);
        } else {
            bestTimeToBuyAndSellStock21(i + 1, i, sum, prices, ans);
        }
    }
}

int bestTimeToBuyAndSellStock31(std::vector<int> &prices) {
    int ans = 0;
    bestTimeToBuyAndSellStock31(0, 0, -1, 0, prices, ans);
    return ans;
}

#endif //ALGORITHM_bestTimeToBuyAndSellStock31_H
