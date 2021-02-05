//
// Created by 张锐 on 2021/2/4.
//

#ifndef ALGORITHM_palindromePartitioning1_H
#define ALGORITHM_palindromePartitioning1_H

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
 *  
 * 2. DFS回溯策略
 *  递归执行字符串的分割，遇到非回文子串时回溯。遇到递归基将当前分割加入结果集中。
 */

#include <vector>
#include <string>

bool isPalindrome(std::string s) {
    std::string t;
    for (char ch: s)
        t += tolower(ch);
    std::string r(t.rbegin(), t.rend());
    return t == r;
}

std::vector<std::vector<std::string>> palindromePartitioning1(std::string s) {
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
        int j;
        for (j = 0; j < l; ++j) {
            if (j - 1 >= 0 && i & 1 << (j - 1)) {   // 分割
                if (!isPalindrome(tmp)) {
                    break;
                }
                curr.push_back(tmp);
                tmp = std::string(1, s[j]);
            } else {
                tmp.append(1, s[j]);
            }
            if (j == l - 1) {
                if (!isPalindrome(tmp))
                    break;
                curr.push_back(tmp);
            }
        }
        if (j == l)
            ans.push_back(curr);
    }
    return ans;
}

void palindromePartitioning2(int index, std::string &s, std::vector<std::string> &curr,
                             std::vector<std::vector<std::string>> &ans) {
    // 递归基础: 分割完成
    if (index == s.size()) {
        if (!curr.empty())
            ans.push_back(curr);
        return;
    }
    for (int i = index; i < s.size(); ++i) {
        std::string tmp = s.substr(index, i - index + 1);
        if (isPalindrome(tmp)) {
            curr.push_back(tmp);
            palindromePartitioning2(i + 1, s, curr, ans);
            curr.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> palindromePartitioning2(std::string s) {
    if (s.empty())
        return {{}};
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> curr;
    std::string tmp(1, s[0]);
    palindromePartitioning2(0, s, curr, ans);
    return ans;
}

#endif //ALGORITHM_palindromePartitioning1_H
