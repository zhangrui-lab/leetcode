//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_ISSCRAMBLE_H
#define ALGORITHM_ISSCRAMBLE_H

/*
 * 87. 扰乱字符串
 *
 *        a     b
 * s1: i.....|.....i+k
 * s2: j.....|.....j+k
 *        a`    b`
 * s2为s1的扰乱字符串，则 a=a`&&b=b` 或者 a=b`&&b=a`;
 *
 * dp[i][j][k]为字符s1[i,i+k), s2[j,j+k)是否为扰乱字符串
 * 原问题的解为 dp[0][0][s1.size];
 *
 * dp[i][j][k] = dp[i][j][w] && dp[i+w]dp[j+w][k-w] || dp[i][j+k-w][w] && dp[i+w][j][k-w]; (k>1)
 *             = s1[i] == s2[j];                                                           (k==1)
 */

#include <string>
#include <vector>

bool isScramble(std::string s1, std::string s2) {
    if (s1.size() != s2.size())
        return false;
    int n = s1.size();
    std::vector<std::vector<std::vector<bool>>> dp(n, std::vector<std::vector<bool>>(n, std::vector<bool>(n+1, false)));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j][1] = s1[i] == s2[j];
    for (int k = 2; k <= n; ++k) {
        for (int i = 0; i <= n - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                for (int w = 1; w < k && !dp[i][j][k]; ++w) {
                    dp[i][j][k] = dp[i][j][k] || dp[i][j][w] && dp[i+w][j+w][k-w] || dp[i][j+k-w][w] && dp[i+w][j][k-w];
                }
            }
        }
    }
    return dp[0][0][n];
}

#endif //ALGORITHM_ISSCRAMBLE_H
