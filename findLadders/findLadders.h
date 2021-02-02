//
// Created by 张锐 on 2021/2/2.
//

#ifndef ALGORITHM_FINDLADDERS_H
#define ALGORITHM_FINDLADDERS_H

/*
 * 126. 单词接龙 II
 *  给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：
 *  每次转换只能改变一个字母。
 *  转换后得到的单词必须是字典中的单词。
 *  说明:
 *      如果不存在这样的转换序列，返回一个空列表。
 *      所有单词具有相同的长度。
 *      所有单词只由小写字母组成。
 *      字典中不存在重复的单词。
 *      你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 *
 * 原单词与每次转换改变一个字母后所得到的单词具有连接关系。原问题为求由 {beginWord, endWord} U wordList 所构成的无向图上
 * 的 beginWord 到 endWord 的给定节点对之间的最短路径。
 *
 * 1. BFS 搜索(无向图)
 *  依据能否转换构造无向图
 *  BFS遍历无向图
 *  回溯产生解
 */



#include <vector>
#include <string>
#include <queue>

std::vector<std::vector<int>> generateMatrix(std::string &beginWord, std::vector<std::string> &wordList) {
    int n = wordList.size() + 1;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    auto canTrans = [](std::string &word1, std::string &word2) {
        int diff = 0;
        for (int i = 0; i < word1.size(); ++i)
            if (word1[i] != word2[i])
                diff++;
        return diff == 1;
    };
    for (int i = 1; i < n; ++i) {
        matrix[0][i] = canTrans(beginWord, wordList[i - 1]);
        matrix[i][0] = 0;
    }
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            matrix[i][j] = canTrans(wordList[i - 1], wordList[j - 1]);
    return matrix;
}

// todo 只实现了寻找一条路径
std::vector<std::vector<std::string>>
findLadders(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
    std::vector<std::vector<std::string>> ans;
    if (std::find(wordList.cbegin(), wordList.cend(), endWord) == wordList.cend())
        return ans;
    enum Status {
        unknow, discovered, visited
    };
    int n = wordList.size() + 1;
    std::vector<std::vector<int>> matrix = generateMatrix(beginWord, wordList);
    std::vector<Status> status(n, unknow);
    std::vector<int> parent(n, -1);
    status[0] = visited;
    std::queue<int> queue;
    queue.push(0);
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        status[node] = visited;
        // 找到 endWord
        if (wordList[node - 1] == endWord) {
            std::vector<std::string> tmp;
            while (node != -1) {
                tmp.push_back(wordList[node - 1]);
                node = parent[node];
            }
            tmp.push_back(beginWord);
            ans.push_back(std::vector<std::string>(tmp.rbegin(), tmp.rend()));
            break;
        }
        for (int i = 1; i < n; ++i) {
            if (status[i] == unknow && matrix[node][i]) {
                queue.push(i);
                parent[i] = node;
                status[i] = discovered;
            }
        }
    }
    return ans;
}

#endif //ALGORITHM_FINDLADDERS_H
