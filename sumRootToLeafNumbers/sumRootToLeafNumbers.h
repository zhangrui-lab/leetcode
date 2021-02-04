//
// Created by 张锐 on 2021/2/4.
//

#ifndef ALGORITHM_SUMROOTTOLEAFNUMBERS_H
#define ALGORITHM_SUMROOTTOLEAFNUMBERS_H


/*
 * 129. 求根到叶子节点数字之和
 *  给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
 *  例如，从根到叶子节点路径 1->2->3 代表数字 123。
 *  计算从根到叶子节点生成的所有数字之和。
 *  说明: 叶子节点是指没有子节点的节点。
 *
 * 1. 深度优先
 * 2. 广度优先
 */

#include "../common.h"
#include "queue"

void sumRootToLeafNumbers1(TreeNode *node, int curr, int &sum) {
    if (!node)
        return;
    if (!node->left && !node->right) {
        sum += curr * 10 + node->val;
        return;
    }
    sumRootToLeafNumbers1(node->left, curr * 10 + node->val, sum);
    sumRootToLeafNumbers1(node->right, curr * 10 + node->val, sum);
}

int sumRootToLeafNumbers1(TreeNode *root) {
    int sum = 0;
    sumRootToLeafNumbers1(root, 0, sum);
    return sum;
}


int sumRootToLeafNumbers2(TreeNode *root) {
    int sum = 0;
    if (!root)
        return sum;
    std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
        int size = queue.size();
        while (size--) {
            root = queue.front();
            queue.pop();
            if (!root->left && !root->right) {
                sum += root->val;
            }
            if (root->left) {
                root->left->val = root->val * 10 + root->left->val;
                queue.push(root->left);
            }
            if (root->right) {
                root->right->val = root->val * 10 + root->right->val;
                queue.push(root->right);
            }
        }
    }
    return sum;
}


#endif //ALGORITHM_SUMROOTTOLEAFNUMBERS_H
