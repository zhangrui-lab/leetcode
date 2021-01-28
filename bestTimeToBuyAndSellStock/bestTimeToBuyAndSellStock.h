//
// Created by 张锐 on 2021/1/28.
//

#ifndef ALGORITHM_BESTTIMETOBUYANDSELLSTOCK_H
#define ALGORITHM_BESTTIMETOBUYANDSELLSTOCK_H

/*
 * 121. 买卖股票的最佳时机
 *  给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 *  你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。设计一个算法来计算你所能获取的最大利润。
 *  返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 *  你不能在买入前卖出股票;
 *
 * 遍历数组，寻找位置 i,j (j>i) 。使得 x = prices[j]-prices[i] 取得最大值。若 x < 0 则返回 0。
 *
 * 1. 蛮力策略
 * 2. 记录最低价格，获取最大收益
 */

#include <vector>

int bestTimeToBuyAndSellStock1(std::vector<int> &prices) {
    int maximum = INT_MIN;
    for (int i = 0; i < prices.size(); ++i) {
        for (int j = i + 1; j < prices.size(); ++j) {
            maximum = std::max(maximum, prices[j] - prices[i]);
        }
    }
    return std::max(maximum, 0);
}

int bestTimeToBuyAndSellStock2(std::vector<int> &prices) {
    int maximum = INT_MIN, min = INT_MAX;
    for (int i = 0; i < prices.size(); ++i) {
        if (prices[i] < min) {
            min = prices[i];
        } else if (prices[i] - min > maximum) {
            maximum = prices[i] - min;
        }
    }
    return std::max(maximum, 0);
}


#endif //ALGORITHM_BESTTIMETOBUYANDSELLSTOCK_H
