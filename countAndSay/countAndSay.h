//
// Created by 张锐 on 2021/1/15.
//

#ifndef ALGORITHM_COUNTANDSAY_H
#define ALGORITHM_COUNTANDSAY_H

/*
 * 外观数列
 */

#include <string>
#include <cassert>
#include <unordered_map>


std::string countAndSay(int n) {
    assert(n >= 0);
    static std::unordered_map<int, std::string> desc = {
            {1, "1"},
            {2, "11"},
            {3, "21"},
            {4, "1211"},
            {5, "111221"},
    };
    if (n < 6)
        return desc[n];
    std::string str;
    std::string prevStr = desc[5];
    for (int k = 5; k < n; ++k) {
        int i = 0, j = i;
        for (; j < prevStr.size(); ++j) {
            if (prevStr[i] != prevStr[j]) {
                str.push_back('0' + j - i);
                str.push_back(prevStr[i]);
                i = j;
            }
        }
        if (j - i > 0) {
            str.push_back('0' + j - i);
            str.push_back(prevStr[i]);
        }
        prevStr = str;
        str = "";
    }
    return prevStr;
}

#endif //ALGORITHM_COUNTANDSAY_H
