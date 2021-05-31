//
// Created by Administrator on 2021/5/31.
//

#ifndef ALGORITHM_LONGESTNICESUBstd::string_H
#define ALGORITHM_LONGESTNICESUBstd::string_H

/*
 * 1763. 最长的美好子字符串
 *  当一个字符串 s 包含的每一种字母的大写和小写形式同时出现在 s 中，就称这个字符串 s 是美好字符串。比方说，"abABB" 是美好字符串，因为 'A' 和 'a' 同时出现了，且 'B' 和 'b' 也同时出现了。然而，"abA" 不是美好字符串因为 'b' 出现了，而 'B' 没有出现。
 *  给你一个字符串 s ，请你返回 s 最长的美好子字符串 。如果有多个答案，请你返回最早出现的一个。如果不存在美好子字符串，请你返回一个空字符串。
 *
 * 示例 1：
 *  输入：s = "YazaAay"
 *  输出："aAa"
 *  解释："aAa" 是一个美好字符串，因为这个子串中仅含一种字母，其小写形式 'a' 和大写形式 'A' 也同时出现了。
 *  "aAa" 是最长的美好子字符串。
 *
 * 示例 2：
 *  输入：s = "Bb"
 *  输出："Bb"
 *  解释："Bb" 是美好字符串，因为 'B' 和 'b' 都出现了。整个字符串也是原字符串的子字符串。
 *
 * 蛮力思路: 获取所有子串, 获取其长度最长的美好子字符串.
 *
 */

#include <string>
#include <map>

std::string longestNiceSubstring(std::string s) {
    int n = s.size();
    std::string ans;

    for (int i = 0; i < n; ++i) {
        int a = 0, b = 0;
        for (int j = i; j < n; ++j) {
            if ('a' <= s[j] && s[j] <= 'z') a |= 1 << (s[j] - 'a');
            else b |= 1 << (s[j] - 'A');
            if (a == b && j - i + 1 > ans.size()) {
                ans = s.substr(i, j - i + 1);
            }
        }
    }
    return ans;
}

#endif //ALGORITHM_LONGESTNICESUBstd::string_H
