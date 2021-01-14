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
#include <utility>
#include <unordered_map>

std::vector<std::pair<size_t, std::string>> allMatches(std::string s, std::string word) {
    size_t n = s.size(), m = word.size();
    std::vector<std::pair<size_t, std::string>> pos;
    for (int i = 0, j = 0; i <= n - m; ++i, j = 0) {
        while (j < m && s[i + j] == word[j]) ++j;
        if (j == m) {
            pos.push_back({i, word});
        }
    }
    return pos;
}

// 复杂度过高
// todo 未考虑到题目中长度一致的单词
std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
    std::vector<std::pair<size_t, std::string>> allPos;
    for (int i = 0; i < words.size(); ++i) {
        auto tmp = allMatches(s, words[i]);
        allPos.insert(allPos.end(), tmp.begin(), tmp.end());
    }
    std::sort(allPos.begin(), allPos.end(), [](std::pair<size_t, std::string> p1, std::pair<size_t, std::string> p2) {
        return p1.first <= p2.first;
    });
    allPos.erase(std::unique(allPos.begin(), allPos.end()), allPos.end());
    std::vector<int> matched;
    for (int i = 0, j = i; i < allPos.size(); ++i, j = i) {
        int pos = allPos[j].first;
        std::string word = allPos[j].second;
        std::vector<std::string> tWords = words;
        std::vector<std::string>::iterator wordIter;
        while ((wordIter = std::find(tWords.begin(), tWords.end(), word)) != tWords.end()) {
            tWords.erase(wordIter);
            pos += word.size();
            // 查找为使用的可以拼接当前位置的单词
            while (j < allPos.size() && (std::find(tWords.cbegin(), tWords.cend(), allPos[j].second) == tWords.cend() ||
                                         allPos[j].first != pos)) {
                j++;
            }
            if (j != allPos.size()) {
                word = allPos[j].second;
            } else {
                break;
            }
        }
        if (tWords.empty()) {
            matched.push_back(allPos[i].first);
        }
    }
    return matched;
}

// 朴素算法：尝试所有可能位置并判断是否合法
std::vector<int> findSubstring2(std::string s, std::vector<std::string> &words) {
    std::vector<int> resu;
    size_t n = s.size(), m = words.size(), l = words[0].size();
    std::unordered_map<std::string, size_t> wtol;
    std::for_each(words.cbegin(), words.cend(), [&](const std::string &word) { wtol[word]++; });
    // 遍历所有可能的位置求解
    for (int i = 0; i + m * l <= n; ++i) {
        std::unordered_map<std::string, size_t> wcout;
        // 判断 s[i, i+m*l) 是否为可能的选择
        int j = 0;
        for (j = i; j < i + m * l; j += l) {
            std::string wchar = s.substr(j, l);
            //printf("\t test, i:%d, j:%d, char: %s\n",i, j, wchar.c_str());
            if (wtol.find(wchar) == wtol.cend() || wcout[wchar] >= wtol[wchar]) {
                break;
            }
            wcout[wchar]++;
        }
        if (j == i + m * l) {
            resu.push_back(i);
        }
    }
    return resu;
}


// 滑动窗口算法
std::vector<int> findSubstring1(std::string s, std::vector<std::string> &words) {
    std::vector<int> resu;
    size_t n = s.size(), m = words.size(), l = words[0].size();
    std::unordered_map<std::string, size_t> wtol;
    std::for_each(words.cbegin(), words.cend(), [&](const std::string &word) { wtol[word]++; });
    // 所有可能窗口集合
    for (int i = 0; i < l; ++i) {
        std::unordered_map<std::string, size_t> wcout;
        for (int lo = i, hi = lo; hi + l <= n;) {
            std::string wchar = s.substr(hi, l);
            hi += l;
            //printf("lo:%d, hi:%d,word:%s\n", lo, hi, wchar.c_str());
            // 不合法word
            if (wtol.find(wchar) == wtol.cend()) {
                wcout.clear();
                lo = hi;
                //printf("\tundefined char: %s, lo: %d, hi: %d\n", wchar.c_str(), lo, hi);
                continue;
            }
            wcout[wchar]++;
            while (wcout[wchar] > wtol[wchar]) {
                wcout[s.substr(lo, l)]--;
                lo += l;
                //printf("\tunset char:%s, lo: %d, hi: %d\n", s.substr(lo, l).c_str(), lo, hi);
            }
            if (lo + m * l == hi) {
                //printf("\t\tvalid:%d\n", lo);
                resu.push_back(lo);
            }
        }
    }
    return resu;
}

#endif //ALGORITHM_SUBSTRINGWITHCONCATENATIONOFALLWORDS_H
