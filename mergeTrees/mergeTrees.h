//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_MERGETREES_H
#define ALGORITHM_MERGETREES_H

/**
 * 617. 合并二叉树
 *  给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
 *  你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
 *
 * 求解策略:
 *  1. dfs: 对于root1,root2.
 *      当root1存在时, 将root1的值累加root2的值.
 *      设置当前根节点root为 root1==nullptr ? root2 : root1.
 *      递归左右子节点.
 */

#include <vector>
#include <stack>
#include "../common.h"

using namespace std;

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (root1 != nullptr)
        root1->val = root1->val + (root2 ? root2->val : 0);
    TreeNode *root = root1 == nullptr ? root2 : root1;
    if (root == nullptr) return nullptr;
    root->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
    root->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
    return root;
}

#endif //ALGORITHM_MERGETREES_H
