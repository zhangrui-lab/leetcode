//
// Created by 张锐 on 2021/1/21.
//

#ifndef ALGORITHM_MINIMUMWINDOWSUBSTRING_H
#define ALGORITHM_MINIMUMWINDOWSUBSTRING_H

/*
 * 76. 最小覆盖子串
 *  给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 *  注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 * 滑动窗口策略:
 *  当i,j不是合法的窗口时,扩展j直到窗口 [i,j] 合法。
 *  当i,j是合法的窗口时,扩展i直到窗口 [i,j] 不合法。
 *  每次扩展 i 之前, 更新最小窗口
 * 如何验证窗口是否合法:
 *  窗口内包含目标字符串t的所有字符且使用次数不小于目标字符串。
 */

#include <string>
#include <unordered_map>

std::string minimumWindowSubstring(std::string s, std::string t) {
    if (s.empty() || t.empty())
        return "";
    std::unordered_map<char, int> sm, tm;
    for (int i = 0; i < t.size(); ++i)
        tm[t[i]]++;
    int i = 0, j = i, pos = -1, min = INT_MAX;
    auto valid = [&]() {
        for (auto iter = tm.cbegin(); iter != tm.cend(); iter++)
            if (sm.find(iter->first) == sm.cend() || sm[iter->first] < iter->second)
                return false;
        return true;
    };
    for (; j < s.size(); ++j) {
        if (tm.find(s[j]) != tm.cend()) {
            sm[s[j]]++;
            printf("discovered char:%c=%d\n", s[j], sm[s[j]]);
        }
        while (valid()) {
            if (min > j - i + 1) {
                min = j - i + 1;
                pos = i;
                printf("update min len, pos:%d, min:%d\n", pos, min);
            }
            if (tm.find(s[i]) != tm.cend()) {
                sm[s[i]] = std::max(0, sm[s[i]] - 1);
                printf("unset char:%c=%d\n", s[i], sm[s[i]]);
            }
            i++;
        }
    }
    return pos == -1 ? "" : s.substr(pos, min);
}

#endif //ALGORITHM_MINIMUMWINDOWSUBSTRING_H
