//
// Created by 47302 on 2021/1/11.
//

#ifndef ALGORITHM_LONGESTCOMMONPREFIX_H
#define ALGORITHM_LONGESTCOMMONPREFIX_H

/*
 * 最长公共前缀
 *
 * 1. 依次比较每个字符串的位置 i， 若不同时返回[0,i)。相同时i++，直到达到任意一字符串长度
 * 2. 任选一个字符串作为前缀，并不断同其他字符串进行比较，更新公共前缀
 */

#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string> &strs) {
    if (strs.empty())
        return "";
    int minLen = INT_MAX;
    for (int i = 0; i < strs.size(); ++i)
        if (strs[i].length() < minLen)
            minLen = strs[i].length();

    for (int i = 0; i < minLen; ++i) {
        for (int j = 1; j < strs.size(); ++j) {
            if (strs[j - 1][i] != strs[j][i]) {
                return strs[j].substr(0, i);
            }
        }
    }
    return strs[0].substr(0, minLen);
}

std::string longestCommonPrefix(const std::string &str1, const std::string &str2) {
    int index = 0, len = std::min(str1.size(), str2.size());
    while (index < len && str1[index] == str2[index]) ++index;
    return str1.substr(0, index);
}

std::string longestCommonPrefix1(std::vector<std::string> &strs) {
    if (strs.empty())
        return "";
    std::string prefix = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
        prefix = longestCommonPrefix(prefix, strs[i]);
        if (prefix.empty()) {
            break;
        }
    }
    return prefix;
}

#endif //ALGORITHM_LONGESTCOMMONPREFIX_H
