//
// Created by 张锐 on 2021/3/10.
//

#ifndef ALGORITHM_DISTINCTECHOSUBSTRINGS_H
#define ALGORITHM_DISTINCTECHOSUBSTRINGS_H

/*
 * 1316. 不同的循环子字符串
 *  给你一个字符串 text ，请你返回满足下述条件的不同非空子字符串的数目：
 *      可以写成某个字符串与其自身相连接的形式（即，可以写为 a + a，其中 a 是某个字符串）。
 *  例如，abcabc 就是 abc 和它自身连接形成的。
 * eg:
 *  输入：text = "abcabcabc"
 *  输出：3
 *  解释：3 个子字符串分别为 "abcabc"，"bcabca" 和 "cabcab" 。
 *
 * 我们在 text 中枚举位置 i 和 j，若字符串 text[i:j] 和 text[j:j*2-i] 相等，那么字符串 text[i:j*2-i] 就是一个满足条件的子串，其中 text[x:y] 表示字符串 text 中以位置 x 开始，位置 y 结束并且不包含位置 y 的子串。
 */

#include <string>
#include <unordered_set>

int distinctEchoSubstrings(std::string text) {
    int n = text.size();
    std::unordered_set<std::string_view> seen;
    std::string_view text_v(text);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int l = j - i;
            if (j * 2 - i <= n && text_v.substr(i, l) == text_v.substr(j, l) && !seen.count(text_v.substr(i, l))) {
                ++ans;
                seen.insert(text_v.substr(i, l));
            }
        }
    }
    for (auto iter = seen.cbegin(); iter != seen.cend(); iter++)
        std::cout << *iter << std::endl;
    return ans;
}

#endif //ALGORITHM_DISTINCTECHOSUBSTRINGS_H
