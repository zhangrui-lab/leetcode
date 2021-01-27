//
// Created by 张锐 on 2021/1/27.
//

#ifndef ALGORITHM_MINDEPTHOFTREE_H
#define ALGORITHM_MINDEPTHOFTREE_H

/*
 * 11. 二叉树的最小深度
 *  给定一个二叉树，找出其最小深度。
 *  最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 *  说明：叶子节点是指没有子节点的节点。
 *
 * 1. 深度优先
 * 2. 广度优先
 */

#include "../common.h"
#include <cmath>
#include <queue>

int minDepthOfTree1(TreeNode *root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    int lh = root->left ? minDepthOfTree1(root->left) : INT_MAX;
    int rh = root->right ? minDepthOfTree1(root->right) : INT_MAX;
    return 1 + std::min(lh, rh);
}

int minDepthOfTree2(TreeNode *root) {
    if (!root)
        return 0;
    std::queue<TreeNode *> queue;
    queue.push(root);
    int level = 1;
    while (!queue.empty()) {
        int size = queue.size();
        while (size--) {
            root = queue.front();
            queue.pop();
            if (!root->left && !root->right)
                return level;
            if (root->left)
                queue.push(root->left);
            if (root->right)
                queue.push(root->right);
        }
        level++;
    }
}


#endif //ALGORITHM_MINDEPTHOFTREE_H
