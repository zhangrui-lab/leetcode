//
// Created by Administrator on 2021/8/16.
//

#ifndef ALGORITHM_CALCULATE_H
#define ALGORITHM_CALCULATE_H

/**
 * 227. 基本计算器 II
 *  给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。整数除法仅保留整数部分。
 *
 * 示例 1：
 *  输入：s = "3+2*2"
 *  输出：7
 *
 * 示例 2：
 *  输入：s = " 3/2 "
 *  输出：1
 *
 * 示例 3：
 *  输入：s = " 3+5 / 2 "
 *  输出：5
 *
 * 求解策略:
 *  正规式: int: -?[1-9][0-9]* | 0; sym: (+, -, *, /)
 *  文法:
 *      expr: expr+term | expr-term | term
 *      term: term*fact | term/fact | fact
 *      fact: (expr) | var
 *      var: int | -int
 */

#include <string>
#include <vector>
#include <numeric>

using namespace std;

int calculate(string s) {
    vector<int> stk;
    char preSign = '+';
    int num = 0, n = s.length();
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            num = num * 10 + int(s[i] - '0');
        }
        if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
            switch (preSign) {
                case '+':
                    stk.push_back(num);
                    break;
                case '-':
                    stk.push_back(-num);
                    break;
                case '*':
                    stk.back() *= num;
                    break;
                default:
                    stk.back() /= num;
            }
            preSign = s[i];
            num = 0;
        }
    }
    return accumulate(stk.begin(), stk.end(), 0);
}

#endif //ALGORITHM_CALCULATE_H
