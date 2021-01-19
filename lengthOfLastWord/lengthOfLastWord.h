//
// Created by 张锐 on 2021/1/19.
//

#ifndef ALGORITHM_LENGTHOFLASTWORD_H
#define ALGORITHM_LENGTHOFLASTWORD_H

/*
 * 最后一个单词的长度
 *  给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 *  如果不存在最后一个单词，请返回 0 。说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
 */

#include <string>

int lengthOfLastWord(std::string s) {
    int i, j = s.size() - 1;
    while (j >= 0 && s[j] == ' ') j--;
    for (i = j; i >= 0 && s[i] != ' '; --i);
    return j - i;
}

#endif //ALGORITHM_LENGTHOFLASTWORD_H
