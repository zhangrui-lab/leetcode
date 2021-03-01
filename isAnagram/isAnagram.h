//
// Created by 张锐 on 2021/3/1.
//

#ifndef ALGORITHM_ISANAGRAM_H
#define ALGORITHM_ISANAGRAM_H

/*
 * 242. 有效的字母异位词
 *  给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 */

#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size())
        return false;
    std::map<char, int> counts;
    for (int i = 0; i < s.size(); ++i) {
        counts[s[i]]++;
        counts[t[i]]--;
    }
    for (auto iter = counts.cbegin(); iter != counts.cend(); iter++)
        if (iter->second != 0)
            return false;
    return true;
}

#endif //ALGORITHM_ISANAGRAM_H
