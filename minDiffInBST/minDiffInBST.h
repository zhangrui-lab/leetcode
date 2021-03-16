//
// Created by 张锐 on 2021/3/16.
//

#ifndef ALGORITHM_MINDIFFINBST_H
#define ALGORITHM_MINDIFFINBST_H

/*
 * 783. 二叉搜索树节点最小距离
 *  给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。
 * 注意：
 *  二叉树的大小范围在 2 到 100。
 *  二叉树总是有效的，每个节点的值都是整数，且不重复。
 */

#include "../common.h"
#include "../getMinimumDifference/getMinimumDifference.h"   // 题解相同

void minDiffInBST(TreeNode *root, TreeNode *&prev, int &min) {
    if (!root)
        return;
    minDiffInBST(root->left, prev, min);
    if (prev)
        min = std::min(min, std::abs(prev->val - root->val));
    prev = root;
    minDiffInBST(root->right, prev, min);
}

int minDiffInBST(TreeNode *root) {
    int min = INT_MAX;
    TreeNode *prev = nullptr;
    minDiffInBST(root, prev, min);
    return min;
}

#endif //ALGORITHM_MINDIFFINBST_H
