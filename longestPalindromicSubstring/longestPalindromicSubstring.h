//
// Created by 张锐 on 2021/1/11.
//

#ifndef ALGORITHMS_LONGESTPALINDROMICSUBSTRING_H
#define ALGORITHMS_LONGESTPALINDROMICSUBSTRING_H

/*
 * 最长回文子串
 *
 * 蛮力算法
 *  枚举所有可能子串，验证其是否为回文串。取出其中最长者
 *
 * 动态规划
 * 1. 刻画问题的最优解结构特征
 *      设置函数 f(i, j)  = true，   s[i,j)为s合法子串且为回文串
 *                      =  false， 其他
 *      longestPalindrome(s) => f(0, s.len)
 * 2. 递归的定义问题的最优解
 *      f(i, j) = f(i+1, j-1) && s[i] == s[j];
 * 3. 求解问题的最优解的值
 *      std::string longestPalindrome(std::string s):
 *          for i=0 to n-1:
 *              f(i,i+1)=true;
 *          for l=2 to n:
 *              for i=0 to n-l:
 *                  j=i+l;
 *                  f(i,j) = f(i+1, j-1) && s[i] == s[j];
 *          return f(0,s.len);
 * 4. 依据求解的信息重构问题的最优解
 *
 * 依据回文中心进行扩展
 *  枚举所有的「回文中心」并尝试「扩展」，直到无法扩展为止，此时的回文串长度即为此「回文中心」下的最长回文串长度。我们对所有的长度求出最大值，即可得到最终的答案。
 */

#include <string>
#include <vector>
#include <utility>


// s[l,r]
bool palindromeValid(const std::string &s, int l, int r) {
    while (l <= r && s[l] == s[r]) {
        ++l;
        --r;
    }
    return l > r;
}

std::string longestPalindrome1(std::string s) {
    int n = s.length();
    std::pair<int, int> pos = {0, -1};
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (pos.second - pos.first < j - i && palindromeValid(s, i, j)) {
                pos = {i, j};
            }
        }
    }
    return s.substr(pos.first, pos.second - pos.first + 1);
}


std::string longestPalindrome2(std::string s) {
    int n = s.length();
    std::string palindrome;
    std::vector<std::vector<int>> f(n, std::vector<int>(n));
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i < n - l; ++i) {
            int j = i + l;
            if (l < 2) {
                f[i][j] = s[i] == s[j];
            } else {
                f[i][j] = (s[i] == s[j] && f[i + 1][j - 1]);
            }
            if (f[i][j]) {
                palindrome = s.substr(i, l + 1);
            }
        }
    }
    return palindrome;
}


std::pair<int, int> expandAroundCenter(std::string s, int l, int r) {
    while (l > -1 && r < s.length() && s[l] == s[r]) {
        --l;
        ++r;
    }
    return {l + 1, r - 1};
}


std::string longestPalindrome3(std::string s) {
    std::pair<int, int> pos = {0, -1};
    for (int i = 0; i < s.length(); ++i) {
        std::pair<int, int> p1 = expandAroundCenter(s, i, i);
        std::pair<int, int> p2 = expandAroundCenter(s, i, i + 1);
        if (pos.second - pos.first < p1.second - p1.first) {
            pos = p1;
        }
        if (pos.second - pos.first < p2.second - p2.first) {
            pos = p2;
        }
    }
    return s.substr(pos.first, pos.second - pos.first + 1);
}

int centerSpread(std::string s, int center) {
    int step = 0;
    for (int i = center - 1, j = center + 1; i > -1 && j < s.length() && s[i] == s[j]; --i, ++j, ++step);
    return step;
}

std::string processingString(const std::string &s) {
    std::string o = "#";
    for (int i = 0; i < s.length(); ++i) {
        o += s[i];
        o += "#";
    }
    return o;
}

std::string longestPalindrome4(std::string s) {
    int size = s.size();
    if (size < 2) {
        return s;
    }
    std::string str = processingString(s);
    int sSize = 2 * size + 1;
    int maxLen = 1, start = 0;
    for (int i = 0; i < sSize; i++) {
        int curLen = centerSpread(str, i);
        if (curLen > maxLen) {
            maxLen = curLen;
            start = (i - maxLen) / 2;
        }
    }
    return s.substr(start, maxLen);
}

std::string longestPalindrome5(std::string s) {
    int n = s.size();
    if (n < 2) return s;
    std::string str = processingString(s);
    n = 2 * n + 1;
    int maxRight = 0, center = 0;
    int maxLen = 1, start = 0;
    std::vector<int> locInfo(n, 0);
    for (int i = 0; i < n; ++i) {
        if (i < maxRight) {
            int mir = center * 2 - i;
            locInfo[i] = std::min(locInfo[mir], maxRight - i);
        }
        // 当前 i 尝试进行新的扩展； (locInfo[mir] = maxRight - i 的情况)
        for (int lo = i - locInfo[i] - 1, hi = i + locInfo[i] + 1; lo > -1 && hi < n && str[lo] == str[hi]; --lo, ++hi) {
            locInfo[i]++;
        }
        if (i + locInfo[i] > maxRight) {
            center = i;
            maxRight = i + locInfo[i];
        }
        if (locInfo[i] > maxLen) {
            maxLen = locInfo[i];
            start  = (i - maxLen) / 2;
        }
    }
    return s.substr(start, maxLen);
}

#endif //ALGORITHMS_LONGESTPALINDROMICSUBSTRING_H
