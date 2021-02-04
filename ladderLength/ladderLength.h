//
// Created by 张锐 on 2021/2/2.
//

#ifndef ALGORITHM_LADDERLENGTH_H
#define ALGORITHM_LADDERLENGTH_H

/*
 * 127. 单词接龙
 * 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：
 *  序列中第一个单词是 beginWord 。
 *  序列中最后一个单词是 endWord 。
 *  每次转换只能改变一个字母。
 *  转换过程中的中间单词必须是字典 wordList 中的单词。
 *  给你两个单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。
 */


std::vector<std::vector<int>> generateLadderLengthMatrix(std::string &beginWord, std::vector<std::string> &wordList) {
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

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
    int level = 0;
    if (std::find(wordList.cbegin(), wordList.cend(), endWord) == wordList.cend())
        return level;
    enum Status {
        unknow, discovered, visited
    };
    int n = wordList.size() + 1;
    std::vector<std::vector<int>> matrix = generateLadderLengthMatrix(beginWord, wordList);
    std::vector<Status> status(n, unknow);
    status[0] = visited;
    std::queue<int> queue;
    queue.push(0);
    while (!queue.empty()) {
        level++;
        int size = queue.size();
        while (size--) {
            int node = queue.front();
            queue.pop();
            if (wordList[node - 1] == endWord) {
                return level;
            }
            for (int i = 1; i < n; ++i) {
                if (status[i] == unknow && matrix[node][i]) {
                    queue.push(i);
                    status[i] = visited;
                }
            }
        }
    }
    return 0;
}


#endif //ALGORITHM_LADDERLENGTH_H
