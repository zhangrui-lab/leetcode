//
// Created by Administrator on 2021/7/26.
//

#ifndef ALGORITHM_ISISOMORPHIC_H
#define ALGORITHM_ISISOMORPHIC_H

/**
 * 205. 同构字符串
 *  给定两个字符串 s 和 t，判断它们是否是同构的。
 *  如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
 *  每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
 *
 * 求解策略:
 *  1. 统计字符的出现次数: 当源字符的任意次数都有目标字符与之对应时, 为同构字符串.
 */

#include <map>
#include <string>

using namespace std;

bool isIsomorphic(string s, string t) {
    map<char, char> s2t;
    map<char, char> t2s;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        char x = s[i], y = t[i];
        if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
            return false;
        }
        s2t[x] = y;
        t2s[y] = x;
    }
    return true;
}

#endif //ALGORITHM_ISISOMORPHIC_H
