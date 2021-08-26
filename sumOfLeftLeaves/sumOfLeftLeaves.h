//
// Created by Administrator on 2021/8/26.
//

#ifndef ALGORITHM_SUMOFLEFTLEAVES_H
#define ALGORITHM_SUMOFLEFTLEAVES_H

/**
 * 404. 左叶子之和
 *  计算给定二叉树的所有左叶子之和。
 *
 * 求解策略:
 *  1. dfs
 *  2. bfs
 */

#include <queue>
#include "../common.h"

using namespace std;

bool isLeafNode(TreeNode *node) {
    return !node->left && !node->right;
}

int dfs(TreeNode *node) {
    int ans = 0;
    if (node->left) {
        ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
    }
    if (node->right && !isLeafNode(node->right)) {
        ans += dfs(node->right);
    }
    return ans;
}

int sumOfLeftLeaves(TreeNode *root) {
    return root ? dfs(root) : 0;
}

int sumOfLeftLeaves2(TreeNode *root) {
    if (!root) {
        return 0;
    }
    queue<TreeNode *> q;
    q.push(root);
    int ans = 0;
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left) {
            if (isLeafNode(node->left)) {
                ans += node->left->val;
            } else {
                q.push(node->left);
            }
        }
        if (node->right) {
            if (!isLeafNode(node->right)) {
                q.push(node->right);
            }
        }
    }
    return ans;
}

#endif //ALGORITHM_SUMOFLEFTLEAVES_H
