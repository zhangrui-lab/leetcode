//
// Created by 张锐 on 2021/1/21.
//

#ifndef ALGORITHM_COMBINATIONS_H
#define ALGORITHM_COMBINATIONS_H

/*
 * 77. 组合
 *  给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 *
 * 所有可能的情况，典型DFS
 */

#include <vector>

void combinations1(int n, int k, int index, std::vector<int> &curr, std::vector<std::vector<int>> &ans) {
    if (k <= 0) {
        ans.push_back(curr);
        return;
    }
    for (int i = index; i <= n; ++i) {
        curr.push_back(i);
        combinations1(n, k - 1, i + 1, curr, ans);
        curr.pop_back();
    }
}

std::vector<std::vector<int>> combinations1(int n, int k) {
    std::vector<int> curr;
    std::vector<std::vector<int>> ans;
    combinations1(n, k, 1, curr, ans);
    return ans;
}

#endif //ALGORITHM_COMBINATIONS_H
