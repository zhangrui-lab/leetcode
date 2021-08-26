//
// Created by Administrator on 2021/8/26.
//

#ifndef ALGORITHM_KTHSMALLEST_H
#define ALGORITHM_KTHSMALLEST_H

/**
 * 230. 二叉搜索树中第K小的元素
 *  给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
 *
 * 求解策略:
 *  1. dfs: 搜索时返回root为根的子树的节点数目. 当某节点node的左侧节点数目 + 偏移量为k-1时,返回node;
 *  2. dfs中序遍历: 中序遍历可将树的层序结构转化为升序的线性结构.
 *  3. stack: 利用stack模拟中序遍历,在获取第k小元素时终止.
 */

#include <stack>
#include <vector>
#include <algorithm>
#include "../common.h"

using namespace std;

int kthSmallest(TreeNode *root, int k, int offset, TreeNode *&node) {
    if (root == nullptr)
        return 0;
    if (node)
        return node->val;
    int ln = kthSmallest(root->left, k, offset, node);
    if (offset + ln == k - 1) {
        node = root;
    }
    int rn = kthSmallest(root->right, k, offset + ln + 1, node);
    return ln + rn + 1;
}

int kthSmallest(TreeNode *root, int k) {
    TreeNode *node = nullptr;
    kthSmallest(root, k, 0, node);
    return node->val;
}

vector<int> inorder(TreeNode *root) {
    if (root == nullptr)
        return {};
    vector<int> lv = inorder(root->left), rv = inorder(root->right);
    lv.push_back(root->val);
    lv.insert(lv.end(), rv.begin(), rv.end());
    return lv;
}

int kthSmallest2(TreeNode *root, int k) {
    std::vector<int> seq = inorder(root);
    return seq[k - 1];
}

int kthSmallest3(TreeNode *root, int k) {
    stack<TreeNode *> stk;
    while (true) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        if (--k <= 0) break;
        stk.pop();
        root = root->right;
    }
    return root->val;
}

#endif //ALGORITHM_KTHSMALLEST_H
