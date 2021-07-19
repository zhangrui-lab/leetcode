//
// Created by Administrator on 2021/7/19.
//

#ifndef ALGORITHM_WORDBREAK_H
#define ALGORITHM_WORDBREAK_H

/**
 * 139. 单词拆分
 *  给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 *
 * 说明：
 *  拆分时可以重复使用字典中的单词。
 *  你可以假设字典中没有重复的单词。
 *
 * 示例 1：
 *  输入: s = "leetcode", wordDict = ["leet", "code"]
 *  输出: true
 *  解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 *
 * 示例 2：
 *  输入: s = "applepenapple", wordDict = ["apple", "pen"]
 *  输出: true
 *  解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。 // 注意你可以重复使用字典中的单词。
 *
 * 示例 3：
 *  输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 *  输出: false
 *
 * 求解思路:
 *  1. DFS: 指针p遍历当前字符串.
 *      当p开始的串处存在前缀子串在wordDict中时, 更新p位置. 尝试进行下一次匹配.
 *      当p开始的串处无法找到匹配的前缀时, 进行回溯, 并尝试进行下一次访问, 若都不存在完整的匹配, 则判定 s 不可以被空格拆分为一个或多个在字典中出现的单词。
 *      可将所有wordDict中的首字符获取到字典中, 加快回溯.
 *  2. 对DFS加入记忆: 避免执行重复的计算 (记忆从位置 p 开始的子串能否被拆分)
 *  3. BFS(加入visited数组避免对同样的初始位置进行访问)
 *  4. 动态规划: 对于给定的长度为 l 的字符串, 其是否可被分解取决于所有可能的位置 pos 分割  s, 分割后的子串是否都可被分解. (当前问题的解依赖于相同的子问题的解)
 */

#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

bool doWordBreak(string s, int p, const set<string> &words) {
    if (p == s.length()) {
        return true;
    }
    for (int i = p, l = s.length(); i < l; ++i) {
        if (words.count(s.substr(p, i - p + 1)) && doWordBreak(s, i + 1, words)) {
            return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict) {
    set<string> words;
    for (unsigned int i = 0; i < wordDict.size(); ++i) {
        words.insert(wordDict[i]);
    }
    return doWordBreak(s, 0, words);
}

bool doWordBreak2(string s, int p, const set<string> &words, map<int, bool> &memo) {
    if (p == s.length()) {
        return true;
    }
    if (memo.find(p) != memo.end()) {
        return memo.find(p)->second;
    }
    for (int i = p, l = s.length(); i < l; ++i) {
        if (words.count(s.substr(p, i - p + 1)) && doWordBreak2(s, i + 1, words, memo)) {
            memo[i] = true;
            return true;
        }
    }
    memo[p] = false;
    return false;
}

bool wordBreak2(string s, vector<string> &wordDict) {
    set<string> words;
    map<int, bool> memo;
    for (unsigned int i = 0; i < wordDict.size(); ++i) {
        words.insert(wordDict[i]);
    }
    return doWordBreak2(s, 0, words, memo);
}

bool wordBreak3(string s, vector<string> &wordDict) {
    queue<int> positions;
    positions.push(0);
    set<string> words;
    map<int, bool> visited;
    for (unsigned int i = 0; i < wordDict.size(); ++i) {
        words.insert(wordDict[i]);
    }
    while (!positions.empty()) {
        int pos = positions.front();
        positions.pop();
        if (pos == s.size()) {
            return true;
        }
        if (visited[pos]) {
            continue;
        }
        for (int i = pos, l = s.size(); i < l; ++i) {
            if (words.count(s.substr(pos, i - pos + 1))) {
                positions.push(i + 1);
            }
        }
        visited[pos] = true;
    }
    return false;
}

bool wordBreak4(string s, vector<string> &wordDict) {
    set<string> words;
    for (int i = 0, l = wordDict.size(); i < l; ++i) {
        words.insert(wordDict[i]);
    }
    vector<bool> dp = vector<bool>(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1, l = s.size(); i <= l; ++i) {
        for (int j = 0; j < i && !dp[i]; ++j) {
            dp[i] = dp[j] && words.count(s.substr(j, i - j));
        }
    }
    return dp[s.size()];
}

#endif //ALGORITHM_WORDBREAK_H
