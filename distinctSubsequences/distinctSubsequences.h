//
// Created by 张锐 on 2021/1/28.
//

#ifndef ALGORITHM_DISTINCTSUBSEQUENCES_H
#define ALGORITHM_DISTINCTSUBSEQUENCES_H

/*
 * 115. 不同的子序列
 *  给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
 *  字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "AFCBCEDE" 的一个子序列，而 "AEC" 不是）
 *  题目数据保证答案符合 32 位带符号整数范围。
 *
 * 1. DFS搜索
 * 2. 动态规划
 *  dp[i][j] 为 s 前缀长度为i 和 t 前缀长度为的不同的子序列。
 *  dp[i][j] = dp[i-1][j] + dp[i-1][j-1];  (s[i-1]==t[j-1])
 *           = dp[i-1][j];                 (s[i-1] != t[j-1])
 *           = 1;                          (j==0)
 *           = 0;                          (i==0 && j!= 0)
 *
 * 3. 滚动数组优化空间复杂度
 */

#include <string>
#include <vector>

void distinctSubsequences(int sIndex, int tIndex, int matched, std::string s, std::string t, int &num) {
    if (matched == t.size()) {
        num++;
        return;
    }
    for (int i = sIndex; i < s.size(); ++i)
        if (s[i] == t[tIndex])
            distinctSubsequences(i + 1, tIndex + 1, matched + 1, s, t, num);
}

int distinctSubsequences(std::string s, std::string t) {
    int num = 0;
    distinctSubsequences(0, 0, 0, s, t, num);
    return num;
}


int distinctSubsequences2(std::string s, std::string t) {
    int n = s.size(), m = t.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector(m + 1, 0));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = s[i - 1] == t[j - 1] ? dp[i - 1][j] + dp[i - 1][j - 1] : dp[i - 1][j];
        }
    }
    return dp[n][m];
}

int distinctSubsequences3(std::string s, std::string t) {
    std::vector<long long> dp(t.size() + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < s.size(); i++) {
        for (int j = t.size(); j > 0; j--) {
            if (s[i] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return (int) dp.back();
}


#endif //ALGORITHM_DISTINCTSUBSEQUENCES_H
