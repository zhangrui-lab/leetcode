//
// Created by 47302 on 2021/1/11.
//

#ifndef ALGORITHM_ROMANTOINT_H
#define ALGORITHM_ROMANTOINT_H

#include <string>

/*
 * 罗马数字转整数
 */

int romanToInt(std::string s) {
    std::map<std::string, int> sym = {{"M",  1000},
                                      {"CM", 900},
                                      {"D",  500},
                                      {"CD", 400},
                                      {"C",  100},
                                      {"XC", 90},
                                      {"L",  50},
                                      {"XL", 40},
                                      {"X",  10},
                                      {"IX", 9},
                                      {"V",  5},
                                      {"IV", 4},
                                      {"I",  1}};
    int num = 0;
    for (int i = 0; i < s.length(); ++i) {
        std::map<std::string, int>::const_iterator iter;
        if (i < s.size() - 1 && (iter = sym.find(s.substr(i, 2))) != sym.cend()) {
            num += iter->second;
            i++;
        } else {
            iter = sym.find(s.substr(i, 1));
            num += iter->second;
        }
    }
    return num;
}

int romanToInt1(std::string s) {
    if (s.size() < 1)
        return 0;
    std::map<char, int> sym = {{'M', 1000},
                               {'D', 500},
                               {'C', 100},
                               {'L', 50},
                               {'X', 10},
                               {'V', 5},
                               {'I', 1}};
    int prev = sym[s[0]], num = 0;
    for (int i = 1; i < s.size(); ++i) {
        int n = sym[s[i]];
        if (prev < n) {
            num -= prev;
        } else {
            num += prev;
        }
        prev = n;
    }
    num += prev;
    return num;
}

#endif //ALGORITHM_ROMANTOINT_H
