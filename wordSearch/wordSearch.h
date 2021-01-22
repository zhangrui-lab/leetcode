//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_WORDSEARCH_H
#define ALGORITHM_WORDSEARCH_H

/*
 * 79. 单词搜索
 *  给定一个二维网格和一个单词，找出该单词是否存在于网格中。单词必须按照字母顺序，通过相邻的单元格内的字母构成，
 *  其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *
 * DFS策略探索给定可能位置周围的所有情况，判断是否存在单词；
 */

#include <vector>
#include <string>
#include <utility>

void wordSearch1(int i, int j, int index, std::vector<std::vector<char>> &board, std::string &word, std::vector<std::vector<bool>> &used, bool &exist) {
    if (exist || index >= word.size()) {
        exist = true;
        return;
    }
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || used[i][j] || board[i][j] != word[index])
        return;
    used[i][j] = true;
    wordSearch1(i - 1, j, index+1, board, word, used, exist);
    wordSearch1(i + 1, j, index+1, board, word, used, exist);
    wordSearch1(i, j - 1, index+1, board, word, used, exist);
    wordSearch1(i, j + 1, index+1, board, word, used, exist);
    used[i][j] = false;
}

bool wordSearch1(std::vector<std::vector<char>> &board, std::string word) {
    if (board.empty() || board[0].empty() || word.empty())
        return false;
    std::vector<std::vector<bool>> used(board.size(), std::vector<bool>(board[0].size(), false));
    bool exist = false;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            wordSearch1(i, j, 0, board, word, used, exist);
        }
    }
    return exist;
}


bool
checkWord(std::vector<std::vector<char>> &board, std::vector<std::vector<int>> &visited, int i, int j, std::string &s,
          int k) {
    if (board[i][j] != s[k]) {
        return false;
    } else if (k == s.length() - 1) {
        return true;
    }
    visited[i][j] = true;
    std::vector<std::pair<int, int>> directions{{0,  1},
                                                {0,  -1},
                                                {1,  0},
                                                {-1, 0}};
    bool result = false;
    for (const auto &dir: directions) {
        int newi = i + dir.first, newj = j + dir.second;
        if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
            if (!visited[newi][newj]) {
                bool flag = checkWord(board, visited, newi, newj, s, k + 1);
                if (flag) {
                    result = true;
                    break;
                }
            }
        }
    }
    visited[i][j] = false;
    return result;
}

bool wordSearch2(std::vector<std::vector<char>> &board, std::string word) {
    int h = board.size(), w = board[0].size();
    std::vector<std::vector<int>> visited(h, std::vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            bool flag = checkWord(board, visited, i, j, word, 0);
            if (flag) {
                return true;
            }
        }
    }
    return false;
}

#endif //ALGORITHM_WORDSEARCH_H
