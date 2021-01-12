//
// Created by 张锐 on 2021/1/12.
//

#ifndef ALGORITHMS_VALIDPARENTHESES_H
#define ALGORITHMS_VALIDPARENTHESES_H

#include <string>
#include <stack>
#include <unordered_map>

/*
 * 有效的括号
 *
 * 利用堆栈: 遇到左括号入栈。右括号则出栈，直到遇到第一个匹配的左括号出栈。若出栈过程中未找到匹配的元素或者字符串处理完成后栈中还剩余元素，则无效。
 */

bool validParentheses1(std::string s) {
    std::stack<char> parentheses;
    std::unordered_map<char, char> match = {{')', '('},
                                  {']', '['},
                                  {'}', '{'}};
    for (int i = 0; i < s.size(); ++i) {
        switch (s[i]) {
            case '(':
            case '{':
            case '[':
                parentheses.push(s[i]);
                break;
            default:
                if (parentheses.empty() || parentheses.top() != match[s[i]])
                    return false;
                parentheses.pop();
                break;
        }
    }
    return parentheses.empty();
}

#endif //ALGORITHMS_VALIDPARENTHESES_H
