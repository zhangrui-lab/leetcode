//
// Created by 张锐 on 2021/3/5.
//

#ifndef ALGORITHM_TOLOWERCASE_H
#define ALGORITHM_TOLOWERCASE_H

/*
 * 709. 转换成小写字母
 *  实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
 *
 * 1. 位运算
 *  所有小写字母的 ASCII 码的二进制第六位（从右向左）都是 1 ，而对应的大写字母第六位为 0 ，其他位都一样。
 *  大写转小写是与00100000做或运算，小写转大写是与11011111做与运算
 * 2. HashMap
 * 3. Vector
 */

#include <string>
#include <unordered_map>

std::string toLowerCase(std::string str) {
    for (auto &i :str) {
        i |= 32;
    }
    return str;
}

std::string toLowerCase1(std::string str) {
    std::unordered_map<char, char> mappings = {
            {'A', 'a'},
            {'B', 'b'},
            {'C', 'c'},
            {'D', 'd'},
            {'E', 'e'},
            {'F', 'f'},
            {'G', 'g'},
            {'H', 'h'},
            {'I', 'i'},
            {'J', 'j'},
            {'K', 'k'},
            {'L', 'l'},
            {'M', 'm'},
            {'N', 'n'},
            {'O', 'o'},
            {'P', 'p'},
            {'Q', 'q'},
            {'R', 'r'},
            {'S', 's'},
            {'T', 't'},
            {'U', 'u'},
            {'V', 'v'},
            {'W', 'w'},
            {'X', 'x'},
            {'Y', 'y'},
            {'Z', 'z'},
    };
    for (int i = 0, n = str.size(); i < n; ++i)
        str[i] = mappings.count(str[i]) ? mappings[str[i]] : str[i];
    return str;
}


#endif //ALGORITHM_TOLOWERCASE_H
