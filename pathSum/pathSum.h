//
// Created by 张锐 on 2021/1/27.
//

#ifndef ALGORITHM_HASPATHSUM2_H
#define ALGORITHM_HASPATHSUM2_H


/*
 * 113. 路径总和 II
 *  给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 *  说明: 叶子节点是指没有子节点的节点。
 *
 * 1. 深度优先
 * 2. 广度优先
 */

#include <queue>
#include <vector>
#include <algorithm>
#include "../common.h"
#include <unordered_map>

void pathSum1(TreeNode *root, int targetSum, int sum, std::vector<int> &curr, std::vector<std::vector<int>> &ans) {
    if (!root)
        return;
    if (!root->left && !root->right && root->val + sum == targetSum) {
        curr.push_back(root->val);
        ans.push_back(curr);
        return;
    }
    curr.push_back(root->val);
    if (root->left) {
        pathSum1(root->left, targetSum, sum + root->val, curr, ans);
        curr.pop_back();
    }
    if (root->right) {
        pathSum1(root->right, targetSum, sum + root->val, curr, ans);
        curr.pop_back();
    }
}

std::vector<std::vector<int>> pathSum1(TreeNode *root, int targetSum) {
    std::vector<int> curr;
    std::vector<std::vector<int>> ans;
    pathSum1(root, targetSum, 0, curr, ans);
    return ans;
}


std::vector<std::vector<int>> pathSum2(TreeNode *root, int targetSum) {
    std::vector<std::vector<int>> ans;
    std::unordered_map<TreeNode *, TreeNode *> parents;
    if (!root)
        return ans;
    std::queue<TreeNode *> nodes;
    nodes.push(root);
    std::queue<int> sums;
    sums.push(root->val);
    parents[root] = nullptr;
    while (!nodes.empty()) {
        root = nodes.front();
        nodes.pop();
        int sum = sums.front();
        sums.pop();
        if (root->left) {
            nodes.push(root->left);
            sums.push(root->left->val + sum);
            parents[root->left] = root;
        }
        if (root->right) {
            nodes.push(root->right);
            sums.push(root->right->val + sum);
            parents[root->right] = root;
        }
        if (!root->left && !root->right && sum == targetSum) {
            std::vector<int> curr;
            while (root) {
                curr.push_back(root->val);
                root = parents[root];
            }
            std::reverse(curr.begin(), curr.end());
            ans.push_back(curr);
        }
    }
    return ans;
}


#endif //ALGORITHM_HASPATHSUM2_H
