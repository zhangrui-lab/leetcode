//
// Created by Administrator on 2021/8/16.
//

#ifndef ALGORITHM_INVERTTREE_H
#define ALGORITHM_INVERTTREE_H

/**
 * 翻转一棵二叉树。
 *
 * 求解策略:
 *  1. dfs: 前中后序遍历皆可
 */

#include "common.h"

TreeNode *invertTree(TreeNode *root) {
    if (!root)
        return root;
    invertTree(root->left);
    invertTree(root->right);
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}

#endif //ALGORITHM_INVERTTREE_H
