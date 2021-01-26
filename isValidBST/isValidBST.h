//
// Created by 张锐 on 2021/1/26.
//

#ifndef ALGORITHM_isValidBST_H
#define ALGORITHM_isValidBST_H

/*
 * 98. 验证二叉搜索树
 *  给定一个二叉树，判断其是否是一个有效的二叉搜索树。假设一个二叉搜索树具有如下特征：
 *      节点的左子树只包含小于当前节点的数。
 *      节点的右子树只包含大于当前节点的数。
 *      所有左子树和右子树自身必须也是二叉搜索树。
 *
 * 1. 递归
 * 2. 验证中序遍历是否为升序序列
 */

#include "../common.h"
#include <stack>

bool isValidBST1(TreeNode *root, long lo, long hi) {
    return !root || (lo < root->val && root->val < hi && isValidBST1(root->left, lo, root->val) &&
                     isValidBST1(root->right, root->val, hi));
}

bool isValidBST1(TreeNode *root) {
    return isValidBST1(root, LONG_MIN, LONG_MAX);
}


bool isValidBST2(TreeNode *root) {
    std::stack<TreeNode *> stk;
    std::vector<int> nums;
    auto goLeft = [&](TreeNode *node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    };
    goLeft(root);
    while (!stk.empty()) {
        root = stk.top();
        stk.pop();
        nums.push_back(root->val);
        goLeft(root->right);
    }
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] >= nums[i])
            return false;
    }
    return true;
}


#endif //ALGORITHM_isValidBST_H
