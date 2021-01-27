//
// Created by 张锐 on 2021/1/27.
//

#ifndef ALGORITHM_ISBALANCEDTREE_H
#define ALGORITHM_ISBALANCEDTREE_H

/*
 * 110. 平衡二叉树
 *  给定一个二叉树，判断它是否是高度平衡的二叉树。
 *  本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1。
 *
 * 1. 递归
 */

#include "../common.h"
#include <cmath>

int nodeHeightBalanced(TreeNode *root, bool &balanced) {
    if (!root)
        return 0;
    int lh = nodeHeightBalanced(root->left, balanced);
    int rh = nodeHeightBalanced(root->right, balanced);
    if (std::abs(lh - rh) > 1)
        balanced = false;
    return 1 + std::max(lh, rh);
}

bool isBalancedTree1(TreeNode *root) {
    bool balanced = true;
    nodeHeightBalanced(root, balanced);
    return balanced;
}

#endif //ALGORITHM_ISBALANCEDTREE_H
