//
// Created by 张锐 on 2021/1/18.
//

#ifndef ALGORITHM_GROUPANAGRAMS_H
#define ALGORITHM_GROUPANAGRAMS_H

/*
 * 字母异位词分组
 *  给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 *
 * 直观求解思路
 *  对于每一个字符串，查看其他字符串是否为其字母异位词。
 *
 * 优化策略
 *  获取每一位字符串排序之后的字符串。（排序之后的字符串相等的字符串必定为字母异位词）
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


bool strInAGroup(std::string s1, std::string s2) {
    if (s1.length() != s2.length())
        return false;
    std::unordered_map<char, int> used;
    for (int i = 0; i < s1.size(); ++i) {
        used[s1[i]]++;
        used[s2[i]]--;
    }
    for (auto iter = used.cbegin(); iter != used.cend(); ++iter)
        if (iter->second != 0)
            return false;
    return true;
}

// todo 运行时间超出限制
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
    int n = strs.size();
    std::vector<std::vector<std::string>> groups;
    std::vector<bool> grouped(n, false);
    for (int i = 0; i < n; ++i) {
        if (grouped[i])
            continue;
        grouped[i] = true;
        std::vector<std::string> group(1, strs[i]);
        for (int j = i + 1; j < n; ++j) {
            if (strInAGroup(strs[i], strs[j])) {
                grouped[j] = true;
                group.push_back(strs[j]);
            }
        }
        groups.push_back(group);
    }
    return groups;
}

std::vector<std::vector<std::string>> groupAnagrams1(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (int i = 0; i < strs.size(); ++i) {
        std::string tmp = strs[i];
        std::sort(tmp.begin(), tmp.end());
        if (groups.find(tmp) == groups.cend()) {
            groups[tmp] = std::vector(1, strs[i]);
        } else {
            groups[tmp].push_back(strs[i]);
        }
    }
    std::vector<std::vector<std::string>> resu;
    for (auto iter = groups.cbegin(); iter != groups.cend(); ++iter)
        resu.push_back(iter->second);
    return resu;
}

#endif //ALGORITHM_GROUPANAGRAMS_H
