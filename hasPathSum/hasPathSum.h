//
// Created by 张锐 on 2021/1/27.
//

#ifndef ALGORITHM_HASPATHSUM_H
#define ALGORITHM_HASPATHSUM_H

/*
 * 112. 路径总和
 *  给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
 *  叶子节点 是指没有子节点的节点。
 *
 * 1. 深度优先
 * 2. 广度优先
 */

#include "../common.h"
#include <queue>

void hasPathSum(TreeNode *root, int sum, int targetSum, bool &has) {
    if (!root || has)
        return;
    if (!root->left && !root->right && sum + root->val == targetSum) {
        has = true;
        return;
    }
    if (root->left)
        hasPathSum(root->left, sum + root->val, targetSum, has);
    if (root->right)
        hasPathSum(root->right, sum + root->val, targetSum, has);
}

bool hasPathSum(TreeNode *root, int targetSum) {
    bool has = false;
    hasPathSum(root, 0, targetSum, has);
    return has;
}

bool hasPathSum1(TreeNode *root, int targetSum) {
    if (!root)
        return false;
    if (!root->left && !root->right && root->val == targetSum)
        return true;
    return hasPathSum1(root->left, targetSum - root->val) || hasPathSum1(root->right, targetSum - root->val);
}

bool hasPathSum2(TreeNode *root, int targetSum) {
    if (!root)
        return false;
    std::queue<TreeNode *> nodes;
    std::queue<int> sums;
    nodes.push(root);
    sums.push(root->val);
    while (!nodes.empty()) {
        root = nodes.front();
        nodes.pop();
        int sum = sums.front();
        sums.pop();
        if (!root->left && !root->right && sum == targetSum)
            return true;
        if (root->left) {
            nodes.push(root->left);
            sums.push(sum + root->left->val);
        }
        if (root->right) {
            nodes.push(root->right);
            sums.push(sum + root->right->val);
        }
    }
    return false;
}


#endif //ALGORITHM_HASPATHSUM_H
