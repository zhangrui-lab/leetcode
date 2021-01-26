//
// Created by 47302 on 2021/1/26.
//

#ifndef ALGORITHM_maximumDepthOfBinaryTree1_H
#define ALGORITHM_maximumDepthOfBinaryTree1_H

/*
 * 104. 二叉树的最大深度
 *  给定一个二叉树，找出其最大深度。二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 *  说明: 叶子节点是指没有子节点的节点。
 * 
 * 1. dfs
 * 2. queue
 */

#include "../common.h"
#include <queue>

int maximumDepthOfBinaryTree1(TreeNode *root) {
    if (!root)
        return 0;
    return 1 + std::max(maximumDepthOfBinaryTree1(root->left), maximumDepthOfBinaryTree1(root->right));
}


int maximumDepthOfBinaryTree2(TreeNode *root) {
    if (!root)
        return 0;
    std::queue<TreeNode *> queue;
    queue.push(root);
    int level = 1;
    while (!queue.empty()) {
        int size = queue.size();
        while (size--) {
            root = queue.front(); queue.pop();
            if (root->left)
                queue.push(root->left);
            if (root->right)
                queue.push(root->right);
        }
        level++;
    }
    return level;
}

#endif //ALGORITHM_maximumDepthOfBinaryTree1_H
