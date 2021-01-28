//
// Created by 张锐 on 2021/1/27.
//

#ifndef ALGORITHM_FLATTENTREETOLINKEDLIST_H
#define ALGORITHM_FLATTENTREETOLINKEDLIST_H

/*
 * 114. 二叉树展开为链表
 *  给你二叉树的根结点 root ，请你将它展开为一个单链表：
 *      展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
 *      展开后的单链表应该与二叉树先序遍历顺序相同。
 *
 * 1. 前序遍历实现
 * 2. 迭代实现前序遍历
 * 3. 前序遍历和展开同步进行
 * 4. 寻找前驱节点
 */

#include "../common.h"
#include <vector>
#include <stack>

void flattenTreeToLinkedList(TreeNode *root, std::vector<TreeNode *> &nodes) {
    if (!root)
        return;
    nodes.push_back(root);
    flattenTreeToLinkedList(root->left, nodes);
    flattenTreeToLinkedList(root->right, nodes);
}

void flattenTreeToLinkedList(TreeNode *root) {
    std::vector<TreeNode *> nodes;
    flattenTreeToLinkedList(root, nodes);
    for (int i = 1; i < nodes.size(); ++i) {
        TreeNode *prev = nodes[i - 1], *curr = nodes[i];
        prev->left = nullptr;
        prev->right = curr;
    }
}

void flattenTreeToLinkedList2(TreeNode *root) {
    std::stack<TreeNode *> stk;
    std::vector<TreeNode *> nodes;
    auto visitAndGoLeft = [&](TreeNode *root) {
        while (root) {
            nodes.push_back(root);
            stk.push(root->right);
            root = root->left;
        }
    };
    stk.push(root);
    while (!stk.empty()) {
        root = stk.top();
        stk.pop();
        visitAndGoLeft(root);
    }
    for (int i = 1; i < nodes.size(); ++i) {
        TreeNode *prev = nodes[i - 1], *curr = nodes[i];
        prev->left = nullptr;
        prev->right = curr;
    }
}

void flattenTreeToLinkedList3(TreeNode *root) {
    if (!root)
        return;
    std::stack<TreeNode *> stk;
    stk.push(root);
    TreeNode *prev = nullptr, *curr = nullptr;
    while (!stk.empty()) {
        curr = stk.top();
        stk.pop();
        if (prev) {
            prev->left = nullptr;
            prev->right = curr;
        }
        if (curr->right)
            stk.push(curr->right);
        if (curr->left)
            stk.push(curr->left);
        prev = curr;
    }
}

void flattenTreeToLinkedList4(TreeNode *root) {
    auto findLast = [](TreeNode *root) {
        root = root->left;
        while (root && root->right) {
            root = root->right;
        }
        return root;
    };
    while (root) {
        TreeNode *last = findLast(root);
        if (last) {
            last->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
    }
}


#endif //ALGORITHM_FLATTENTREETOLINKEDLIST_H
