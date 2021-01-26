//
// Created by 张锐 on 2021/1/26.
//

#ifndef ALGORITHM_ISINTERLEAVE_H
#define ALGORITHM_ISINTERLEAVE_H

/*
 * 97. 交错字符串
 * 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。两个字符串 s 和 t 交错的定义与过程如下，其中每个字符串都会被分割成若干非空子字符串：
 *  s = s1 + s2 + ... + sn
 *  t = t1 + t2 + ... + tm
 *  |n - m| <= 1
 *  交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
 *  提示：a + b 意味着字符串 a 和 b 连接。
 *
 * 动态规划算法
 * dp[i][j] 表示 s[1,i] 与 t[1,j] 是否为交错字符串。原文头的解答为 dp[n][m];
 * dp[i][j] = 1;                                                             (i=0,j=0);
 *          = dp[i-1][j] && s[i-1] == s3[i+j-1] || dp[i][j-1] && t[j-1] ==s3[i+j-1]; (i != 0 || j != 0) (数组从0开始技术而此处从1开始，存在1的偏移量)
 *
 * 滚动数组优化空间复杂度
 * dp[i][j] 最多只依赖于前一行(dp[i-1][j])或者前一列(dp[i][j-1])的数据。
 */

#include <string>
#include <vector>

bool isInterleave1(std::string s1, std::string s2, std::string s3) {
    int n = s1.size(), m = s2.size();
    if (n + m != s3.size())
        return false;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i > 0) {
                dp[i][j] |= dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
            }
            if (j > 0) {
                dp[i][j] |= dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            }
        }
    }
    return dp[n][m];
}

bool isInterleave2(std::string s1, std::string s2, std::string s3) {
    int n = s1.size(), m = s2.size(), t = s3.size();
    if (n + m != t)
        return false;
    auto f = std::vector<int>(m + 1, false);
    f[0] = true;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int p = i + j - 1;
            if (i > 0) {
                f[j] &= (s1[i - 1] == s3[p]);
            }
            if (j > 0) {
                f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
            }
        }
    }

    return f[m];
}


#endif //ALGORITHM_ISINTERLEAVE_H
