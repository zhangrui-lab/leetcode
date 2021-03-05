//
// Created by 张锐 on 2021/3/5.
//

#ifndef ALGORITHM_PREORDERTRAVERSAL_H
#define ALGORITHM_PREORDERTRAVERSAL_H

/*
 * 144. 二叉树的前序遍历
 *  给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 * 1. 递归
 * 2. stack实现 todo
 */

#include <stack>
#include <vector>
#include "../common.h"

void preorderTraversal(TreeNode *root, std::vector<int> &ans) {
    if (!root)
        return;
    ans.push_back(root->val);
    preorderTraversal(root->left, ans);
    preorderTraversal(root->right, ans);
}

std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> ans;
    preorderTraversal(root, ans);
    return ans;
}

std::vector<int> preorderTraversal1(TreeNode *root) {
    std::vector<int> ans;
    std::stack<TreeNode *> stk;
    auto visitAndGoLeft = [&ans, &stk](TreeNode *node) {
        while (node) {
            ans.push_back(node->val);
            stk.push(node->right);
            node = node->left;
        }
    };
}

#endif //ALGORITHM_PREORDERTRAVERSAL_H
