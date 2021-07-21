//
// Created by Administrator on 2021/7/21.
//

#ifndef ALGORITHM_EVALRPN_H
#define ALGORITHM_EVALRPN_H

/**
 * 150. 逆波兰表达式求值
 *  根据逆波兰表示法，求表达式的值。有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 *
 * 说明：
 *  整数除法只保留整数部分。
 *  给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 *
 * 示例 1：
 *  输入：tokens = ["2","1","+","3","*"]
 *  输出：9
 *  解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
 *
 * 示例 2：
 *  输入：tokens = ["4","13","5","/","+"]
 *  输出：6
 *  解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
 *
 * 求解思路:
 *  stack
 */

#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cctype>

using namespace std;

int evalRPN(vector<string> &tokens) {
    auto isNumber = [](string &token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    };
    stack<int> stk;
    for (int i = 0, l = tokens.size(); i < l; ++i) {
        if (isNumber(tokens[i])) {
            stk.push(atoi(tokens[i].c_str()));
        } else {
            int opr = stk.top();
            stk.pop();
            int opl = stk.top();
            stk.pop();
            switch (tokens[i][0]) {
                case '+':
                    stk.push(opl + opr);
                    break;
                case '-':
                    stk.push(opl - opr);
                    break;
                case '*':
                    stk.push(opl * opr);
                    break;
                case '/':
                    stk.push(opl / opr);
                    break;
            }
        }
    }
    return stk.top();
}

#endif //ALGORITHM_EVALRPN_H
