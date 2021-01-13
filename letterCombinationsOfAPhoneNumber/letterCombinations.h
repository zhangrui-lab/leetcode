//
// Created by 张锐 on 2021/1/12.
//

#ifndef ALGORITHMS_LETTERCOMBINATIONS_H
#define ALGORITHMS_LETTERCOMBINATIONS_H

#include <vector>
#include <string>
#include <map>

/*
 * 电话号码的字母组合
 *
 * 将每一个数字假设为一个节点，其可能出现的字符为可以进行探索的路径。 尝试对其进行dfs搜索
 *
 * (每个节点有多种可能的选择， 问题本身包含多个节点。)
 */


void letterCombinations(std::string &digits, int pos, std::string &str, std::vector<std::string> &combinations) {
    static std::map<char, std::string> numMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    if (pos >= digits.size()) {
        combinations.push_back(str);
    } else {
        auto chars = numMap[digits[pos]];
        for (int i = 0; i < chars.size(); ++i) {
            str.push_back(chars[i]);
            letterCombinations(digits, pos + 1, str, combinations);
            str.pop_back();
        }
    }
}

std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> combinations;
    if (digits.empty())
        return combinations;
    std::string str;
    letterCombinations(digits, 0, str, combinations);
    return combinations;
}

#endif //ALGORITHMS_LETTERCOMBINATIONS_H
