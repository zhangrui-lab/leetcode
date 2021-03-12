//
// Created by 张锐 on 2021/3/12.
//

#ifndef ALGORITHM_REVERSEVOWELS_H
#define ALGORITHM_REVERSEVOWELS_H

/*
 * 345. 反转字符串中的元音字母
 *  编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * eg:
 *  输入："hello"
 *  输出："holle"
 *
 *  输入："leetcode"
 *  输出："leotcede"
 *
 * 提示：
 *  元音字母不包含字母 "y" 。
 *
 * 1. 双指针
 */

#include <string>
#include <unordered_set>

std::string reverseVowels(std::string s) {
    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int lo = 0, hi = s.size() - 1;
    while (lo < hi) {
        while (lo < hi && !vowels.count(s[lo])) lo++;
        while (lo < hi && !vowels.count(s[hi])) hi--;
        std::swap(s[lo++], s[hi--]);
    }
    return s;
}

#endif //ALGORITHM_REVERSEVOWELS_H
