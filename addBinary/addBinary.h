//
// Created by 张锐 on 2021/1/20.
//

#ifndef ALGORITHM_ADDBINARY_H
#define ALGORITHM_ADDBINARY_H

/*
 * 二进制求和
 *  给你两个二进制字符串，返回它们的和（用二进制表示）。输入为 非空 字符串且只包含数字 1 和 0。
 */

#include <string>

std::string addBinary(std::string a, std::string b) {
    std::string ans;
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i > -1 || j > -1 || carry) {
        int num = (i > -1 ? a[i]-'0' : 0) + (j > -1 ? b[j]-'0' : 0) + carry;
        ans.push_back(num%2 + '0');
        carry = num/2;
        --i;--j;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

#endif //ALGORITHM_ADDBINARY_H
