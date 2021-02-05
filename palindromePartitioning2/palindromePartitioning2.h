//
// Created by 张锐 on 2021/2/5.
//

#ifndef ALGORITHM_PALINDROMEPARTITIONING2_H
#define ALGORITHM_PALINDROMEPARTITIONING2_H

/*
 * 132. 分割回文串 II
 *  给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 *  返回符合要求的最少分割次数。
 * 示例:
 *  输入: "aab"
 *  输出: 1
 *  解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 *
 * 1. 获取分割回文串的 DFS 树的最小深度
 * 2. 动态规划
 *  令 dp[i] 为分割 s[0, i] 回文串的最少分割次数。 则原问题解为 dp[s.size()-1]
 *  dp[i] = std::min(dp[i], dp[j] + 1); for j=0 to i; (i != 0)
 *        = 0; (i == 0)
 */

#include <string>
#include <vector>
#include "../palindromePartitioning/palindromePartitioning.h"

void palindromePartitioning21(int index, std::string &s, int depth, int &min) {
    if (index == s.size()) {
        min = std::min(min, depth);
        return;
    }
    for (int i = index; i < s.size(); ++i) {
        std::string tmp = s.substr(index, i - index + 1);
        if (isPalindrome(tmp))
            palindromePartitioning21(i + 1, s, depth + 1, min);
    }
}

int palindromePartitioning21(std::string s) {
    int min = INT_MAX;
    palindromePartitioning21(0, s, 0, min);
    return min > 0 ? min - 1 : min;
}


int palindromePartitioning22(std::string s) {
    int n = s.size();
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    std::vector<std::vector<bool>> isPalindromic(n, std::vector<bool>(n, false));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i <= 1 || isPalindromic[i + 1][j - 1])) {
                isPalindromic[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        if (isPalindromic[0][i]) {
            dp[i] = 0;
            continue;
        }
        for (int j = 0; j < i; ++j) {
            if (isPalindromic[j + 1][i]) {
                dp[i] = std::min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1];
}

#endif //ALGORITHM_PALINDROMEPARTITIONING2_H
