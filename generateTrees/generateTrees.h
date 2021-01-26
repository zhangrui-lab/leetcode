//
// Created by 张锐 on 2021/1/26.
//

#ifndef ALGORITHM_GENERATETREES_H
#define ALGORITHM_GENERATETREES_H

/*
 * 95. 不同的二叉搜索树 II
 *  给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
 *
 * DFS深度优先策略
 */

#include <vector>
#include "../common.h"
#include <queue>

std::vector<TreeNode *> generateTrees(int lo, int hi) {
    if (lo > hi)
        return {nullptr};
    std::vector<TreeNode *> trees;
    for (int i = lo; i <= hi; ++i) {
        std::vector<TreeNode *> lts = generateTrees(lo, i - 1);
        std::vector<TreeNode *> rts = generateTrees(i + 1, hi);
        for (auto &left: lts) {
            for (auto &right: rts) {
                trees.push_back(new TreeNode(i, left, right));
            }
        }
    }
    return trees;
}


std::vector<TreeNode *> generateTrees(int n) {
    if (n <= 0)
        return {};
    return generateTrees(1, n);
}

#endif //ALGORITHM_GENERATETREES_H
