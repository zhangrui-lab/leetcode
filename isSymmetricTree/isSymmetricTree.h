//
// Created by 47302 on 2021/1/26.
//

#ifndef ALGORITHM_ISSYMMETRICTREE_H
#define ALGORITHM_ISSYMMETRICTREE_H

/*
 * 101. 对称二叉树
 *  给定一个二叉树，检查它是否是镜像对称的。
 *
 * 1. 深度优先
 * 2. 迭代判定
 */

#include "../common.h"
#include <queue>

bool isSymmetricTree1(TreeNode *node1, TreeNode *node2) {
    if (node1 == nullptr || node2 == nullptr)
        return node1 == node2;
    return node1->val == node2->val && isSymmetricTree1(node1->left, node2->right) &&
           isSymmetricTree1(node1->right, node2->left);
}

bool isSymmetricTree1(TreeNode *root) {
    return !root || isSymmetricTree1(root->left, root->right);
}


bool isSymmetricTree2(TreeNode *root) {
    if (!root)
        return true;
    std::queue<TreeNode *> queue;
    queue.push(root->left);
    queue.push(root->right);
    while (!queue.empty()) {
        TreeNode *node1 = queue.front();
        queue.pop();
        TreeNode *node2 = queue.front();
        queue.pop();
        if (node1 == nullptr && node2 == nullptr)
            continue;
        if (node1 == nullptr || node2 == nullptr || node1->val != node2->val)
            return false;
        queue.push(node1->left);
        queue.push(node2->right);
        queue.push(node1->right);
        queue.push(node2->left);
    }
    return true;
}


#endif //ALGORITHM_ISSYMMETRICTREE_H
