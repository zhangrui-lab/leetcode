//
// Created by 张锐 on 2021/1/29.
//

#ifndef ALGORITHM_BESTTIMETOBUYANDSELLSTOCK2_H
#define ALGORITHM_BESTTIMETOBUYANDSELLSTOCK2_H

/*
 * 122. 买卖股票的最佳时机 II
 *  给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 *  设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 *  注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 * 1. DFS: 获取每一天皆 买入/卖出 情况下所能获取的最大收益.
 * 				   	715364
 *				/			\            \    			....
 *			15364            5364		 364
 *			/			       \		    \
 *       5364(-6)		     364(4)	     64(-2)         ....
 *        /						 \			   \
 *      364						 64			    4	    ....
 *     /						   \			 \
 *     64(-8)					  4[7]		    [-4]
 *    /
 *   4
 *  /
 * [-10]
 *
 * 2. 动态规划
 *  观察上诉 DFS 递归调用树可知。问题求解过程中存在大量的重复子问题。
 *  令 dp[i][0] 表示第 i 天结束且手中无股票时的最大收益。dp[i][1] 表示第 i 天结束且手中有股票时的最大收益。
 *  dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i]);
 *  dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] - prices[i]);
 * 3. 优化动态规划空间复杂度
 *   dp[i][0] 和 dp[i][1] 都只依赖于 dp[i-1][0] 和 dp[i-1][1]， 故只需要常数级别的存储空间。
 * 4. 贪心策略
 */


#include <vector>

void bestTimeToBuyAndSellStock21(int day, int buyDay, int sum, std::vector<int> &prices, int &maximum) {
    if (day == prices.size()) {
        maximum = std::max(sum, maximum);
        return;
    }
    for (int i = day; i < prices.size(); ++i) {
        // 卖出
        if (buyDay >= 0) {
            bestTimeToBuyAndSellStock21(i + 1, -1, sum + prices[i] - prices[buyDay], prices, maximum);
        } else {    // 买入
            bestTimeToBuyAndSellStock21(i + 1, i, sum, prices, maximum);
        }
    }
}

int bestTimeToBuyAndSellStock21(std::vector<int> &prices) {
    int maximum = INT_MIN;
    bestTimeToBuyAndSellStock21(0, -1, 0, prices, maximum);
    return maximum;
}

int bestTimeToBuyAndSellStock22(std::vector<int> &prices) {
    if (prices.empty())
        return 0;
    int n = prices.size();
    int dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
}


int bestTimeToBuyAndSellStock23(std::vector<int> &prices) {
    if (prices.empty())
        return 0;
    int n = prices.size();
    int pn = 0, ph = -prices[0];
    for (int i = 1; i < n; ++i) {
        int cn = std::max(pn, ph + prices[i]);
        int ch = std::max(ph, pn - prices[i]);
        pn = cn;
        ph = ch;
    }
    return pn;
}

int bestTimeToBuyAndSellStock24(std::vector<int> &prices) {
    int maximum = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i - 1] < prices[i]) {
            maximum += std::max(0, prices[i] - prices[i - 1]);
        }
    }
    return maximum;
}


#endif //ALGORITHM_BESTTIMETOBUYANDSELLSTOCK2_H
