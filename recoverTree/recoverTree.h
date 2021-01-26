//
// Created by 张锐 on 2021/1/26.
//

#ifndef ALGORITHM_RECOVERTREE_H
#define ALGORITHM_RECOVERTREE_H

/*
 * 99. 恢复二叉搜索树
 *  给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
 *  进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？
 *
 * 1. 显式中序遍历获取并修复非法节点
 * 2. 隐式中序遍历获取并修复非法节点
 * 3. Morris 中序遍历
 */

#include "../common.h"

void recoverTree1(TreeNode *root) {
    std::stack<TreeNode *> stk;
    std::vector<TreeNode *> nodes;
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
        nodes.push_back(root);
        goLeft(root->right);
    }
    int i = -1, j = -1;
    for (int k = 1; k < nodes.size(); ++k) {
        if (nodes[k - 1]->val >= nodes[k]->val)
            (i == -1 ? i : j) = k - 1;
    }
    if (j != -1)
        std::swap(nodes[i]->val, nodes[j + 1]->val);
    else
        std::swap(nodes[i]->val, nodes[i + 1]->val);
}


void recoverTree2(TreeNode *root) {
    std::stack<TreeNode *> stk;
    std::vector<TreeNode *> nodes;
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
        nodes.push_back(root);
        goLeft(root->right);
    }
    TreeNode *i = nullptr, *j = nullptr, *prev = nullptr;
    while (!stk.empty()) {
        root = stk.top();
        stk.pop();
        if (prev && prev->val >= root->val) {
            j = root;
            if (i == nullptr) {
                i = prev;
            } else {
                break;;
            }
        }
        prev = root;
        goLeft(root->right);
    }
}

void recoverTree3(TreeNode *root) {
    auto findPredecessor = [](TreeNode *node) {
        TreeNode *predecessor = node->left;
        while (predecessor->right && predecessor->right != node) predecessor = predecessor->right;
        return predecessor;
    };
    TreeNode *i = nullptr, *j = nullptr, *pred = nullptr, *predecessor = nullptr;
    auto verify = [&](TreeNode *node) {
        if (pred && pred->val >= node->val) {
            j = node;
            if (i == nullptr) {
                i = pred;
            }
        }
    };
    while (root != nullptr) {
        if (root->left) {
            predecessor = findPredecessor(root);
            if (predecessor->right == nullptr) {
                predecessor->right = root;
                root = root->left;
            } else {
                verify(root);
                pred = root;
                predecessor->right = nullptr;
                root = root->right;
            }
        } else {
            verify(root);
            pred = root;
            root = root->right;
        }
    }
    std::swap(i->val, j->val);
}

#endif //ALGORITHM_RECOVERTREE_H
