//
// Created by 张锐 on 2021/2/1.
//

#ifndef ALGORITHM_BINARYTREEMAXIMUMPATHSUM_H
#define ALGORITHM_BINARYTREEMAXIMUMPATHSUM_H

/*
 * 124. 二叉树中的最大路径和
 *  路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 *  路径和是路径中各节点值的总和。
 *  给你一个二叉树的根节点 root ，返回其最大路径和 。
 *
 * 1. DFS
 *  当前节点的最大路径和为: std::max(root->val, 左子节点的最大路径和, 右子节点的最大路径和, root->val + 左子节点的最大路径和 + 右子节点的最大路径和);
 *  当取 root->val + 左子节点的最大路径和 + 右子节点的最大路径和 时，无法向上回溯。故使用额外空间保存
 */

#include "../common.h"

int binaryTreeMaximumPathSum(TreeNode *root, int &max) {
    if (!root)
        return 0;
    int lMax = std::max(binaryTreeMaximumPathSum(root->left, max), 0);
    int rMax = std::max(binaryTreeMaximumPathSum(root->right, max), 0);
    max = std::max(max, lMax + rMax + root->val);
    return root->val + std::max(lMax, rMax);
}

int binaryTreeMaximumPathSum(TreeNode *root) {
    int max = INT_MIN;
    binaryTreeMaximumPathSum(root, max);
    return max;
}

#endif //ALGORITHM_BINARYTREEMAXIMUMPATHSUM_H
