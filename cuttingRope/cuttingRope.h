//
// Created by 张锐 on 2021/3/12.
//

#ifndef ALGORITHM_CUTTINGROPE_H
#define ALGORITHM_CUTTINGROPE_H

/*
 * 剑指 Offer 14-I. 剪绳子
 *  给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
 *  请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 * eg
 *  示例 1：
 *  输入: 2
 *  输出: 1
 *  解释: 2 = 1 + 1, 1 × 1 = 1
 *
 *  示例 2:
 *  输入: 10
 *  输出: 36
 *  解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
 *
 * 1. DFS遍历所有情况 O(2^{n-1})
 *  将其看作为长度为n的01串,考虑所有可能的01组合。
 *
 * 2. 带备忘录的递归防止重复求解相同子问题
 *
 * 3. 动态规划
 *  dp[i] 表示长度为 i 的绳子的最大乘积。
 *  剪绳子的解: dp[n]
 *  dp[i] = for(j=1 to i) j * dp[i-j];
 *
 * 4. 动态规划优化    // todo
 * 5. 数学
 */

#include <vector>
#include <unordered_map>

int cuttingRope(int n, std::vector<int> &curr) {
    if (n <= 0) {
        if (curr.size() > 1) {
            int sum = 1;
            for (int i = 0, n = curr.size(); i < n; ++i) {
                sum *= curr[i];
            }
            return sum;
        }
        return 0;
    }

    int max = 0;
    for (int i = 1; i <= n; i++) {
        curr.push_back(i);
        max = std::max(max, cuttingRope(n - i, curr));
        curr.pop_back();
    }
    return max;
}

int cuttingRope(int n) {
    std::vector<int> curr;
    return cuttingRope(n, curr);
}

int cuttingRope2(int n, std::vector<int> &memo) {
    if (memo[n])
        return memo[n];
    int max = 0;
    for (int i = 1; i < n; ++i)
        max = std::max(max, std::max(i * (n - i), i * cuttingRope2(n - i, memo)));
    memo[n] = max;
    return memo[n];
}

int cuttingRope2(int n) {
    std::vector<int> memo(n + 1);
    memo[2] = 1;
    return cuttingRope2(n, memo);
}

int cuttingRope3(int n) {
    std::vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; j++) {
            dp[i] = std::max(dp[i], std::max(j * (i - j), j * dp[i - j]));
        }
    }
    return dp[n];
}

#endif //ALGORITHM_CUTTINGROPE_H
