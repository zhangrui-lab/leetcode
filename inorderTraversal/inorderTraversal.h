//
// Created by 47302 on 2021/1/23.
//

#ifndef ALGORITHM_INORDERTRAVERSAL_H
#define ALGORITHM_INORDERTRAVERSAL_H

/*
 * 94. 二叉树的中序遍历
 *  给定一个二叉树的根节点 root ，返回它的中序遍历。
 *
 * 1. 递归实现
 * 2. stack替换递归
 * 3. Morris 中序遍历
 *  在遍历到节点r时，若r存在未访问的直接前驱节点x，则将其后向指针指向r。遍历左子树，在达到x时回到r。
 *  在遍历到节点r时，若r不存在未访问的直接前驱节点，则直接访问当前节点并跳转到右子树。
 */

#include <vector>
#include "../common.h"

void inorderTraversal1(TreeNode *root, std::vector<int>& ans) {
    if (!root)
        return;
    inorderTraversal(root->left, ans);
    ans.push_back(root->val);
    inorderTraversal(root->right, ans);
}

std::vector<int> inorderTraversal1(TreeNode *root) {
    std::vector<int> ans;
    inorderTraversal(root, ans);
    return ans;
}


std::vector<int> inorderTraversal2(TreeNode *root) {
    std::vector<int> ans;
    std::stack<TreeNode *> stk;
    auto goLeft = [&](TreeNode *node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    };
    goLeft(root);
    while (!stk.empty()) {
        TreeNode *node = stk.top();
        stk.pop();
        ans.push_back(node->val);
        goLeft(node->right);
    }
    return ans;
}

#endif //ALGORITHM_INORDERTRAVERSAL_H
