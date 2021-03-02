//
// Created by 张锐 on 2021/3/2.
//

#ifndef ALGORITHM_FINDANAGRAMS_H
#define ALGORITHM_FINDANAGRAMS_H

/*
 * 438. 找到字符串中所有字母异位词
 *  给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
 *  字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
 *  说明：
 *  字母异位词指字母相同，但排列不同的字符串。
 *  不考虑答案输出的顺序。
 *
 * 1. 蛮力
 *  找到 s 中所有长度为 p.size 的子串，判断是否为p的字母异位词。
 * 2. 蛮力优化
 *  从左至右查看所有的起始位置index。 当已index开头的子串因某一字符x无法构成p的字母异位词时。
 *      a. x在p中不存在，index越过x所在位置继续查看。
 *      b. x在以index为起始的子串中出现次数多于在p中出现次数，index越过s[x]继续查看。
 * 3. 滑动窗口策略
 *  todo
 */


#include <vector>
#include <string>
#include <unordered_map>

std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> ans;
    int n = s.size(), m = p.size();
    for (int i = 0; i <= n - m; ++i) {
        std::unordered_map<char, int> count;
        bool legal = true;
        for (int j = 0; j < m; ++j)
            count[s[i + j]]++;
        for (int j = 0; j < m; ++j)
            legal = legal && --count[p[j]] >= 0;
        if (legal)
            ans.push_back(i);
    }
    return ans;
}

std::vector<int> findAnagrams1(std::string s, std::string p) {
    std::vector<int> res;
    int m[128] = {0};
    int left = 0, right = 0, need = 0;
    for (char c : p)
        ++m[c];
    while (right < s.size()) {
        if (m[s[right]] > 0) ++need;
        --m[s[right]];
        ++right;
        while (need == p.size()) {
            if (right - left == p.size()) res.push_back(left);
            if (m[s[left]] == 0) --need;
            ++m[s[left]];
            ++left;
        }
    }
    return res;
}

#endif //ALGORITHM_FINDANAGRAMS_H
