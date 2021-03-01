//
// Created by 张锐 on 2021/3/1.
//

#ifndef ALGORITHM_NUMWAYS_H
#define ALGORITHM_NUMWAYS_H

/*
 * 剑指 Offer 10-II. 青蛙跳台阶问题
 *  一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
 *  答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 *
 * 递归求解:
 *  numWays(n)=numWays(n-1) + numWays(n-2);
 * 动态规划
 *  dp[i] = dp[i-1] + dp[i-2]
 */

#include <map>
#include <vector>

int numWays(int n, std::map<int, int> ways) {
    if (n <= 2)
        ways[n] = n == 2 ? 2 : 1;
    if (ways.find(n) != ways.cend())
        return ways[n];
    ways[n] = (numWays(n - 1, ways) + numWays(n - 2, ways)) % 1000000007;
    return ways[n];
}

int numWays(int n) {
    std::map<int, int> ways;
    return numWays(n, ways);
}

int numWays1(int n) {
    if (n <= 2)
        return n == 2 ? 2 : 1;
    std::vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < n + 1; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    return dp[n];
}

int numWays2(int n) {
    if (n <= 2)
        return n == 2 ? 2 : 1;
    int dp0 = 1, dp1 = 2;
    for (int i = 3; i < n + 1; ++i) {
        int tmp = (dp1 + dp0) % 1000000007;
        dp0 = dp1;
        dp1 = tmp;
    }
    return dp1;
}

#endif //ALGORITHM_NUMWAYS_H
