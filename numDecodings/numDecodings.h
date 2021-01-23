//
// Created by 47302 on 2021/1/23.
//

#ifndef ALGORITHM_NUMDECODINGS_H
#define ALGORITHM_NUMDECODINGS_H

/*
 * 91. 解码方法
 *
 * 获取只含数字的非空字符串 num 的所有可能组合。若每一个组合中的各元素皆合法，则其为一个合法的解码，若不合法则抛弃。
 * 动态规划
 */

#include <string>

int numDecodings(std::string s) {
    if (s.empty() || s[0] == '0')
        return 0;
    int prev = 1, curr = 1;
    for (int i = 1; i < s.size(); ++i) {
        int tmp = curr;
        if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2')
                curr = prev;
            else
                return 0;
        } else if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6') {
            curr = curr + prev;
        }
        prev = tmp;
    }
    return curr;
}

#endif //ALGORITHM_NUMDECODINGS_H
