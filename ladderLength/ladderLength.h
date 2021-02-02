//
// Created by 张锐 on 2021/2/2.
//

#ifndef ALGORITHM_LADDERLENGTH_H
#define ALGORITHM_LADDERLENGTH_H

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
    enum Status { unknow, discovered, visited };
    int n = wordList.size() + 1;
    std::vector<std::vector<int>> matrix = generateLadderLengthMatrix(beginWord, wordList);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    std::vector<Status> status(n, unknow);
    status[0] = visited;
    std::queue<int> queue;
    queue.push(0);
    while (!queue.empty()) {
        level++;
        int size = queue.size();
        while (size--) {
            int node = queue.front();
            printf("level: %d, node: %d\n", level, node);
            queue.pop();
            if (wordList[node - 1] == endWord) {
                printf("wordList[%d] == %s\n", node, endWord.c_str());
                return level;
            }
            for (int i = 1; i < n; ++i) {
                if (status[i] == unknow && matrix[node][i]) {
                    printf("node %d discovered %d\n", node, i);
                    queue.push(i);
                    status[i] = visited;
                }
            }
        }
    }
    return 0;
}


#endif //ALGORITHM_LADDERLENGTH_H
