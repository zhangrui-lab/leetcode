//
// Created by 张锐 on 2021/1/13.
//

#ifndef ALGORITHM_SUBSTRINGWITHCONCATENATIONOFALLWORDS_H
#define ALGORITHM_SUBSTRINGWITHCONCATENATIONOFALLWORDS_H

/*
 * 串联所有单词的子串
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 *
 * 蛮力策略
 *  遍历words，查看所有单词在s中所有出现位置。
 *  遍历所有出现位置，判断当前位置是否可构成words完全匹配的子串
 *
 */

#include <vector>
#include <string>

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
}

#endif //ALGORITHM_SUBSTRINGWITHCONCATENATIONOFALLWORDS_H
