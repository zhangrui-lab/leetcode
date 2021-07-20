//
// Created by Administrator on 2021/7/19.
//

#ifndef ALGORITHM_WORDBREAK2_H
#define ALGORITHM_WORDBREAK2_H

/**
 * 140. 单词拆分 II
 *  给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
 *
 * 说明：
 *  分隔时可以重复使用字典中的单词。
 *  你可以假设字典中没有重复的单词。
 *
 * 示例 1：
 *  输入: s = "catsanddog" wordDict = ["cat", "cats", "and", "sand", "dog"]
 *  输出: ["cats and dog", "cat sand dog"]
 *
 * 示例 2：
 *  输入: s = "pineapplepenapple", wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 *  输出: ["pine apple pen apple", "pineapple pen apple", "pine applepen apple"]
 *
 * 求解思路: (参考 139. 单词拆分)
 */

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void wordBreak(int p, string s, set<string> &wordDict, map<int, vector<string>> &memo) {
    if (memo.find(p) != memo.end())
        return;
    if (p == s.length()) {
        memo[p] = {""};
        return;
    }
    memo[p] = {};
    for (int i = p, l = s.length(); i < l; ++i) {
        string tmp = s.substr(p, i - p + 1);
        if (wordDict.count(tmp)) {
            wordBreak(i + 1, s, wordDict, memo);
            for (const string &succ: memo[i + 1]) {
                memo[p].push_back(succ.empty() ? tmp : tmp + " " + succ);
            }
        }
    }
}

vector<string> wordBreak(string s, vector<string> &wordDict) {
    map<int, vector<string>> memo;
    set<string> words(wordDict.begin(), wordDict.end());
    wordBreak(0, s, words, memo);
    return memo[0];
}

#endif //ALGORITHM_WORDBREAK2_H
