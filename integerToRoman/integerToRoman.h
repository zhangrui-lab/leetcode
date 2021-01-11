//
// Created by 47302 on 2021/1/11.
//

#ifndef ALGORITHM_INTEGERTOROMAN_H
#define ALGORITHM_INTEGERTOROMAN_H

/*
 * 整数转罗马数字
 *
 * 1. 贪心策略：尽可能多的选择较大数字。
 * 2. 利用符号表：对每位中的所有可能取值进行制表，查表返回
 */

std::string intToRoman1(int num) {
    std::vector<std::string> sym = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    std::vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string roman;
    for (int i = 0; i < sym.size() && num > 0; ++i) {
        while (nums[i] <= num) {
            num -= nums[i];
            roman.append(sym[i]);
        }
    }
    return roman;
}

std::string intToRoman2(int num) {
    std::vector<std::string> thousands = {"", "M", "MM", "MMM"};
    std::vector<std::string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    std::vector<std::string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    std::vector<std::string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    std::vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
}

#endif //ALGORITHM_INTEGERTOROMAN_H
