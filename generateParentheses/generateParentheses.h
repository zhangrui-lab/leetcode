//
// Created by 张锐 on 2021/1/12.
//

#ifndef ALGORITHM_GENERATEPARENTHESES_H
#define ALGORITHM_GENERATEPARENTHESES_H

/*
 * 括号生成: 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
 * 蛮力策略
 *  枚举所有可能出现的字符串情况(使用深度优先策略)，验证并记录为合法括号表达式的字符串。
 *  复杂度：字符串长度2n,每个位置可能为(,)。故 O(2^(2n)*n).
 *
 * 优化策略
 *  dfs搜索 + 回溯 + 剪枝
 *  剪枝策略
 *      当前括号表达式前缀子串已不合法。
 */

#include <vector>
#include <string>

void generateParenthesis1(std::string &par, int len, std::vector<std::string> &parenthesis) {
    // 验证是否为合法括号表达式
    if (len == 0) {
        int num = 0;
        for (int i = 0; i < par.size() && num >= 0; ++i) {
            par[i] == '(' ? num++ : num--;
        }
        if (num == 0) {
            parenthesis.push_back(par);
        }
        return;
    }
    par.push_back('(');
    generateParenthesis1(par, len - 1, parenthesis);
    par.pop_back();
    par.push_back(')');
    generateParenthesis1(par, len - 1, parenthesis);
    par.pop_back();
}

std::vector<std::string> generateParenthesis1(int n) {
    std::string str;
    std::vector<std::string> parenthesis;
    generateParenthesis1(str, 2 * n, parenthesis);
    return parenthesis;
}

void generateParenthesis2(std::string &par, int len, std::vector<std::string> &parenthesis, bool (*validator)(std::string)) {
    // 验证是否为合法括号表达式
    if (len == 0) {
        if (validator(par)) {
            parenthesis.push_back(par);
        }
        return;
    }
    par.push_back('(');
    generateParenthesis1(par, len - 1, parenthesis);
    par.pop_back();
    par.push_back(')');
    generateParenthesis1(par, len - 1, parenthesis);
    par.pop_back();
}

std::vector<std::string> generateParenthesis1(int n) {
    std::string str;
    std::vector<std::string> parenthesis;
    generateParenthesis1(str, 2 * n, parenthesis);
    return parenthesis;
}

#endif //ALGORITHM_GENERATEPARENTHESES_H
