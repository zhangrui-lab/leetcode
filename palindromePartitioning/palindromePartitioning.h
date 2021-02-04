//
// Created by 张锐 on 2021/2/4.
//

#ifndef ALGORITHM_PALINDROMEPARTITIONING_H
#define ALGORITHM_PALINDROMEPARTITIONING_H

/*
 * 131. 分割回文串
 *  给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 *  返回 s 所有可能的分割方案。
 * eg:
 *  输入: "aab"
 *  [
 *      ["aa","b"],
 *      ["a","a","b"]
 *  ]
 * 1. 蛮力策略
 *  获取所有子串分割，若当前分割所得的所有子串为回文串则加入结果集中。
 */

#include <vector>
#include <string>
#include "../isPalindrome/isPalindrome.h"

std::vector<std::vector<std::string>> palindromePartitioning(std::string s) {
    // max: 100; 00 ~ 11
    // abc
    // 00: abc
    // 01: ab c
    // 10: a bc
    // 11: a b c
    std::vector<std::vector<std::string>> ans;
    if (s.empty())
        return {{}};
    int l = s.size(), n = 1 << (l - 1);
    for (int i = 0; i < n; ++i) {
        std::vector<std::string> curr;
        std::string tmp;
        // 第 j 位为1表示字符串在 s[j+1] 处发生切割
        for (int j = 0; j < l; ++j) {
            if (j - 1 >= 0 && i & 1 << (j - 1)) {   // 分割
                curr.push_back(tmp);
                tmp = std::string(1, s[j]);
            } else {
                tmp.append(1, s[j]);
            }
            if (j == l - 1)
                curr.push_back(tmp);
        }
        int k = 0;
        for (; k < curr.size() && isPalindrome2(curr[k]); ++k);
        if (k == curr.size())
            ans.push_back(curr);
    }
    return ans;
}

#endif //ALGORITHM_PALINDROMEPARTITIONING_H
