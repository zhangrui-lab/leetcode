//
// Created by 张锐 on 2021/3/2.
//

#ifndef ALGORITHM_MINCHARACTERS_H
#define ALGORITHM_MINCHARACTERS_H

/*
 * 1737. 满足三条件之一需改变的最少字符数
 *  给你两个字符串 a 和 b ，二者均由小写字母组成。一步操作中，你可以将 a 或 b 中的任一字符改变为任一小写字母 。
 *  操作的最终目标是满足下列三个条件之一 ：
 *  a 中的每个字母在字母表中严格小于 b 中的每个字母。
 *  b 中的每个字母在字母表中严格小于 a 中的每个字母。
 *  a 和 b 都由同一个字母组成。
 *  返回达成目标所需的最少操作数。
 */

#include <string>
#include <cassert>
#include <vector>

int minCharacters(std::string a, std::string b) {
    assert(!(a.empty() ^ b.empty()));
    int sa = a.size(), sb = b.size();
    std::vector<int> ca(26), cb(26);
    for (int i = 0; i < sa; ++i)
        ca[a[i] - 'a']++;
    for (int i = 0; i < sb; ++i)
        cb[b[i] - 'a']++;
    int maxC = 0;
    for (int i = 0; i < 26; ++i)
        maxC = maxC < ca[i] + cb[i] ? ca[i] + cb[i] : maxC;
    int min = sa + sb - maxC;
    int ta = 0, tb = 0;
    for (int i = 25; i > 0; --i) {
        ta += ca[i];
        tb += cb[i];
        min = std::min(min, std::min(ta + sb - tb, tb + sa - ta));
    }
    return min;
}

#endif //ALGORITHM_MINCHARACTERS_H
