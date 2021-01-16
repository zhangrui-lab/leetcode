//
// Created by 47302 on 2021/1/16.
//

#ifndef ALGORITHM_MULTIPLYSTRINGS_H
#define ALGORITHM_MULTIPLYSTRINGS_H

#include <string>

/*
 * 字符串相乘
 *  给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 *
 * 1. 通过模拟「竖式乘法」的方法计算乘积。从右往左遍历乘数，将乘数的每一位与被乘数相乘得到对应的结果，再将每次得到的结果累加。
 * 2. 通过数组优化「竖式乘法」之后的加法运算
 */

std::string addStrings(std::string &num1, std::string &num2) {
    std::string ans;
    int i = num1.size() - 1, j = num2.size() - 1, add = 0;
    while (i >= 0 || j >= 0 || add != 0) {
        printf("%d, %d\n", i, j);
        int x = i >= 0 ? num1[i--] - '0' : 0;
        int y = j >= 0 ? num2[j--] - '0' : 0;
        int tmp = x + y + add;
        ans.push_back(tmp % 10);
        add = tmp / 10;
    }
    std::reverse(ans.begin(), ans.end());
    for (auto &c : ans) {
        c += '0';
    }
    return ans;
}

std::string multiplyStrings1(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    std::string ans = "0";
    int m = num1.size(), n = num2.size();
    for (int i = n - 1; i >= 0; i--) {
        std::string curr;
        int add = 0;
        for (int j = n - 1; j > i; j--) {
            curr.push_back(0);
        }
        int y = num2.at(i) - '0';
        for (int j = m - 1; j >= 0; j--) {
            int x = num1.at(j) - '0';
            int product = x * y + add;
            curr.push_back(product % 10);
            add = product / 10;
        }
        while (add != 0) {
            curr.push_back(add % 10);
            add /= 10;
        }
        std::reverse(curr.begin(), curr.end());
        for (auto &c : curr) {
            c += '0';
        }
        ans = addStrings(ans, curr);
    }
    return ans;
}

std::string multiplyStrings2(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    int m = num1.size(), n = num2.size();
    auto ansArr = std::vector<int>(m + n);
    for (int i = m - 1; i >= 0; i--) {
        int x = num1.at(i) - '0';
        for (int j = n - 1; j >= 0; j--) {
            int y = num2.at(j) - '0';
            ansArr[i + j + 1] += x * y;
        }
    }
    for (int i = m + n - 1; i > 0; i--) {
        ansArr[i - 1] += ansArr[i] / 10;
        ansArr[i] %= 10;
    }
    int index = ansArr[0] == 0 ? 1 : 0;
    std::string ans;
    while (index < m + n) {
        ans.push_back(ansArr[index]);
        index++;
    }
    for (auto &c: ans) {
        c += '0';
    }
    return ans;
}


#endif //ALGORITHM_MULTIPLYSTRINGS_H
