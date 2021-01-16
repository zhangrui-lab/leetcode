//
// Created by 47302 on 2021/1/16.
//

#ifndef ALGORITHM_WILDCARDMATCHING_H
#define ALGORITHM_WILDCARDMATCHING_H

/*
 * 通配符匹配
 *  给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 *  '?' 可以匹配任何单个字符。'*' 可以匹配任意字符串（包括空字符串）。两个字符串完全匹配才算匹配成功。
 *
 * 1. 动态规划
 *
 * dp[i][j] 表示字符串 t[0,i), p[0,j) 的匹配情况。
 *
 * matches
 *  t[i] == p[j] || p[i] == ?
 *
 * dp[i][j] = dp[i-1][j-1] ^ matches(t[i], p[j]);   (p[j] != *)
 *          = dp[i-1][j];                           (p[j] == * ^ p[j]匹配t[i])
 *          = dp[i][j-1];                           (p[j] == * ^ p[j]不去匹配t[i])
 *          = true;                                 (i, j == 0)
 *
 *
 * 2. dfs策略
 * 对于模式串中任意的*，都尽可能使其匹配更多的字符。试探其是否能成功匹配，若不能时，减少匹配的数量，继续试探。
 *
 */

#include <string>
#include <vector>

bool wildcardMatching(std::string s, std::string p) {
    int m = s.size();
    int n = p.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        if (p[i - 1] == '*') {
            dp[0][i] = true;
        } else {
            break;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[m][n];
}
#endif //ALGORITHM_WILDCARDMATCHING_H
