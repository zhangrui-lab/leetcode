//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_ISSCRAMBLE_H
#define ALGORITHM_ISSCRAMBLE_H

/*
 * 87. 扰乱字符串
 *
 * 动态规划求解
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
 *
 *
 */

#include <string>
#include <vector>

bool isScramble1(std::string s1, std::string s2) {
    if (s1.size() != s2.size())
        return false;
    int n = s1.size();
    std::vector<std::vector<std::vector<bool>>> dp(n,
                                                   std::vector<std::vector<bool>>(n, std::vector<bool>(n + 1, false)));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j][1] = s1[i] == s2[j];
    for (int k = 2; k <= n; ++k) {
        for (int i = 0; i <= n - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                for (int w = 1; w < k && !dp[i][j][k]; ++w) {
                    dp[i][j][k] = dp[i][j][k] || dp[i][j][w] && dp[i + w][j + w][k - w] ||
                                  dp[i][j + k - w][w] && dp[i + w][j][k - w];
                }
            }
        }
    }
    return dp[0][0][n];
}

bool scramble1Recursion(std::string s1, std::string s2) {
    if (s1 == s2)
        return true;
    //防止超时，若s1中所有字符在s2中不都存在，说明s1无论怎么分割和s2无法匹配，直接返回false，大大优化效率
    std::string t1 = s1, t2 = s2;
    std::sort(t1.begin(), t1.end());
    std::sort(t2.begin(), t2.end());
    if (t1 != t2)
        return false;
    //i从1到s1.size-1，不能从下标0开始，至少分割1个字符出来，否则无法跳出循环
    for (int i = 1; i < s1.size(); i++) {
        //将s1分割成[0,i)[i,s1.size)对应s2匹配可能是[0,i)[i,s1.size)也可能是[s2.size-i,s2.size)[0,s2.size()-i)
        bool flag1 = scramble1Recursion(s1.substr(0, i), s2.substr(0, i)) &&
                     scramble1Recursion(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i));
        bool flag2 = scramble1Recursion(s1.substr(0, i), s2.substr(s2.size() - i, i)) &&
                     scramble1Recursion(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i));
        if (flag1 || flag2)
            return true;
    }
    return false;
}

bool isScramble2(std::string s1, std::string s2) {
    if (s1.size() != s2.size())
        return false;
    return scramble1Recursion(s1, s2);
}


#endif //ALGORITHM_ISSCRAMBLE_H
