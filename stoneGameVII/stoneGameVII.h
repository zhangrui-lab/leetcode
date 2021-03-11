//
// Created by 张锐 on 2021/3/11.
//

#ifndef ALGORITHM_STONEGAMEVII_H
#define ALGORITHM_STONEGAMEVII_H

/*
 * 1690. 石子游戏 VII
 *  石子游戏中，爱丽丝和鲍勃轮流进行自己的回合，爱丽丝先开始 。
 *  有 n 块石子排成一排。每个玩家的回合中，可以从行中移除最左边的石头或最右边的石头，并获得与该行中剩余石头值之和相等的得分。当没有石头可移除时，得分较高者获胜。
 *  鲍勃发现他总是输掉游戏（可怜的鲍勃，他总是输），所以他决定尽力减小得分的差值 。爱丽丝的目标是最大限度地扩大得分的差值 。
 *  给你一个整数数组 stones ，其中 stones[i] 表示从左边开始的第 i 个石头的值，如果爱丽丝和鲍勃都发挥出最佳水平，请返回他们得分的差值 。
 * eg:
 *  输入：stones = [5,3,1,4,2]
 *  输出：6
 *  解释：
 *      爱丽丝移除 2 ，得分 5 + 3 + 1 + 4 = 13 。游戏情况：爱丽丝 = 13 ，鲍勃 = 0 ，石子 = [5,3,1,4] 。
 *      鲍勃移除 5 ，得分 3 + 1 + 4 = 8 。游戏情况：爱丽丝 = 13 ，鲍勃 = 8 ，石子 = [3,1,4] 。
 *      爱丽丝移除 3 ，得分 1 + 4 = 5 。游戏情况：爱丽丝 = 18 ，鲍勃 = 8 ，石子 = [1,4] 。
 *      鲍勃移除 1 ，得分 4 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [4] 。
 *      爱丽丝移除 4 ，得分 0 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [] 。
 *      得分的差值 18 - 12 = 6 。
 *  输入：stones = [7,90,5,1,100,10,10,2]
 *  输出：122
 *
 * 1. 动态规划
 *  dp[i][j] 表示轮到这一个人（无论是 A 或者 B）选时，他能得到与另一个人最大的得分差；
 *  dl[i] 表示在 stones[i] ~ stones[j] 中移除左边界时能获得的分数。dr[j] 表示在 stones[i] ~ stones[j] 中移除右边界时能获得的分数。
 *      dp[i][j] = std::max(dl[i] - dp[i+1][j], dr[j] - dp[i][j-1]);
 *      dl[i],dr[j]应当用前缀和策略进行求解：
 *      dl[i] = pSum[j] - pSum[i];
 *      dr[j] = pSum[j-1] - (i > 0 ? pSum[i-1] : 0);
 */

#include <vector>

int stoneGameVII(std::vector<int> &stones) {
    int n = stones.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    std::vector<int> pSum(n, 0);
    for (int i = 0; i < n; ++i)
        pSum[i] = i > 0 ? pSum[i - 1] + stones[i] : stones[i];
    for (int i = n - 2; i >= 0; i--)
        for (int j = i + 1; j < n; ++j)
            dp[i][j] = std::max(pSum[j] - pSum[i] - dp[i + 1][j],
                                pSum[j] - (i > 0 ? pSum[i - 1] : 0) - stones[j] - dp[i][j - 1]);
    return dp[0][n - 1];
}

#endif //ALGORITHM_STONEGAMEVII_H
