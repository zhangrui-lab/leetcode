//
// Created by 张锐 on 2021/1/11.
//

#ifndef ALGORITHMS_ZIGZAGCONVERSION_H
#define ALGORITHMS_ZIGZAGCONVERSION_H

/*
 *  Z 字形变换
 *  解题思路，按行正序追加字符，并处第一行和最后一行以外的逆序追加字符。知道字符串处理完成。
 *
 *  n = 3:
 *  a   a; a[0], a[4],
 *  a x a; a[1], a[3], a[5]
 *  a   a; a[2], a[6]
 *
 *  n = 4:
 *  a     a; a[0], a[6]
 *  a   x a; a[1], a[5], a[7]
 *  a x   a; a[2], a[4], a[8]
 *  a     a; a[3], a[9]
 *
 *  优化
 */

#include <string>

std::string zigZagConversion(std::string s, int numRows) {
    std::string buf[numRows];
    int p = 0;
    while (true) {
        for (int i = 0; i < numRows && p < s.length(); ++i) {
            buf[i].append(1, s[p++]);
        }
        for (int i = numRows - 2; i > 0 && p < s.length(); --i) {
            buf[i].append(1, s[p++]);
        }
        if (p >= s.length())
            break;
    }
    std::string res;
    for (int j = 0; j < numRows; ++j) {
        res.append(buf[j]);
    }
    return res;
}

#endif //ALGORITHMS_ZIGZAGCONVERSION_H
