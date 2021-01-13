//
// Created by 张锐 on 2021/1/7.
//

#ifndef ALGORITHMS_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H
#define ALGORITHMS_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H

#include <string>

// 最长不重复子串

// f(i) = 考察以i结尾的不重复子串的长度
// 原问题的解：max(f(i)); (i in 0 ~ s.len-1)
// f(i) => f(i+1)
//  0 ~ i 中寻找 j: 1. s[j] == s[i+1]; f(i+1) = f(i)+1;
//                 2. s[j] != s[i+1]; f(i+1) = i-j;
unsigned int lengthOfLongestSubstring1(const std::string &s) {
    int len = 0, max = len;
    for (int i = 0, j = i; i < s.length(); ++i, j = i) {
        while (--j >= i - len && s[i] != s[j]);
        len = i - j;
        max = std::max(len, max);
    }
    return max;
}

// 使用数组记录输入元素最后出现的位置；
unsigned int lengthOfLongestSubstring2(const std::string &s) {
    const int NUMS = 256;
    int m[NUMS] = {-1}, repeat = -1, max = 0;
    for (int i = 0; i < s.length(); ++i) {
        // 在较近位置发生重复
        if (m[s[i]] != -1 && repeat < m[s[i]]) {
            repeat = m[s[i]];
        }
        if (i - repeat > max) {
            max = i - repeat;
        }
        m[s[i]] = i;
    }
    return max;
}

#endif //ALGORITHMS_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H
