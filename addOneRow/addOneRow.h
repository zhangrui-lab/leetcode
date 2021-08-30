//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_ADDONEROW_H
#define ALGORITHM_ADDONEROW_H

/**
 * 623. 在二叉树中增加一行
 *  给定一个二叉树，根节点为第1层，深度为 1。在其第 d 层追加一行值为 v 的节点。
 *  添加规则：给定一个深度值 d （正整数），针对深度为 d-1 层的每一非空节点 N，为 N 创建两个值为 v 的左子树和右子树。
 *  将 N 原先的左子树，连接为新节点 v 的左子树；将 N 原先的右子树，连接为新节点 v 的右子树。如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。
 *
 * 求解策略: 获取要添加层的上一层 level, 为 level 层节点设置新子节点.
 *  1. 层序遍历
 *  2. dfs
 */

#include <queue>
#include <vector>
#include "../common.h"

using namespace std;

TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (root == nullptr) return root;
    if (depth == 1) return new TreeNode(val, root, nullptr);
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        --depth;
        // 再当前que中保留要被加入的层的上一层.
        while (depth == 1 && !que.empty()) {
            TreeNode *node = que.front();
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
            que.pop();
        }
        int size = que.size();
        while (size--) {
            if (que.front()->left) que.push(que.front()->left);
            if (que.front()->right) que.push(que.front()->right);
            que.pop();
        }
    }
    return root;
}

void dfs(TreeNode *root, int val, int depth, int level) {
    if (root == nullptr) return;
    if (level == depth - 1) {
        root->left = new TreeNode(val, root->left, nullptr);
        root->right = new TreeNode(val, nullptr, root->right);
    } else {
        dfs(root->left, val, depth, level + 1);
        dfs(root->right, val, depth, level + 1);
    }
}

TreeNode *addOneRow2(TreeNode *root, int val, int depth) {
    if (root == nullptr) return root;
    if (depth == 1) return new TreeNode(val, root, nullptr);
    dfs(root, val, depth, 1);
    return root;
}


#endif //ALGORITHM_ADDONEROW_H
