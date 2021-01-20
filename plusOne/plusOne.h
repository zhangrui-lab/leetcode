//
// Created by 张锐 on 2021/1/20.
//

#ifndef ALGORITHM_PLUSONE_H
#define ALGORITHM_PLUSONE_H

/*
 * 加一
 *  给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。最高位数字存放在数组的首位，数组中每个元素只存储单个数字。你可以假设除了整数0之外，这个整数不会以零开头。
 */

#include <vector>

std::vector<int> plusOne(std::vector<int> &digits) {
    int carry = 1, i = digits.size() - 1;
    while (i > -1 || carry != 0) {
        int num = (i > -1 ? digits[i] : 0) + carry;
        if (i == -1)
            digits.insert(digits.begin(), num % 10);
        else
            digits[i] = num % 10;
        carry = num / 10;
        if (i != -1)
            i--;
    }
    return digits;
}

#endif //ALGORITHM_PLUSONE_H
