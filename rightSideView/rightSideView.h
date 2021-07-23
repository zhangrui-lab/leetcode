//
// Created by Administrator on 2021/7/23.
//

#ifndef ALGORITHM_RIGHTSIDEVIEW_H
#define ALGORITHM_RIGHTSIDEVIEW_H

/**
 * 199. 二叉树的右视图
 *  给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 *
 * 求解思路:
 *  1. DFS: 优先访问右子树, 并记录当前右侧最大深度, 当当前被访问节点大于右侧最大深度时, 可被看到并更新最大深度.
 *  2. BFS: 同一层节点从右到左入队列, 对于每一层的节点序列, 只有第一个(最右侧节点)可以被看到.
 */

#include <queue>
#include <vector>
#include "../common.h"

using namespace std;

void rightSideView(TreeNode *root, int hight, int &maxDeep, vector<int> &ans) {
    if (!root)
        return;
    if (hight > maxDeep) {
        maxDeep = hight;
        ans.push_back(root->val);
    }
    rightSideView(root->right, hight + 1, maxDeep, ans);
    rightSideView(root->left, hight + 1, maxDeep, ans);
}

vector<int> rightSideView(TreeNode *root) {
    int maxDeep = -1;
    vector<int> ans;
    rightSideView(root, 0, maxDeep, ans);
    return ans;
}

vector<int> rightSideView2(TreeNode *root) {
    vector<int> ans;
    if (!root)
        return ans;
    queue<TreeNode *> que;
    que.push(root);
    TreeNode *node;
    while (!que.empty()) {
        int size = que.size();
        ans.push_back(que.front()->val);
        while (size--) {
            node = que.front();
            if (node->right) que.push(node->right);
            if (node->left) que.push(node->left);
            que.pop();
        }
    }
    return ans;
}

#endif //ALGORITHM_RIGHTSIDEVIEW_H
