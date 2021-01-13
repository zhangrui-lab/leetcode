//
// Created by 张锐 on 2021/1/13.
//

#ifndef ALGORITHM_IMPLEMENTSTRSTR_H
#define ALGORITHM_IMPLEMENTSTRSTR_H

/*
 * 实现 strStr() 函数
 *  给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1
 *
 *
 * 蛮力策略
 *  遍历文本串和模式串所有可能位置。逐字符比较直至模式串溢出。
 *
 * KMP
 * BM
 * dfa
 * sunday
 * ....
 */

#include <string>

int strStr(std::string haystack, std::string needle) {
    if (needle.empty())
        return 0;
    if (haystack.empty())
        return -1;
    int n = haystack.size(), m = needle.size();
    for (int i = 0, j = 0; i <= n - m; ++i, j = 0) {
        while (j < m && haystack[i + j] == needle[j]) j++;
        if (j == m)
            return i;
    }
    return -1;
}


#endif //ALGORITHM_IMPLEMENTSTRSTR_H
