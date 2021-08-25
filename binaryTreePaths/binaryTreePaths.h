//
// Created by Administrator on 2021/8/25.
//

#ifndef ALGORITHM_BINARYTREEPATHS_H
#define ALGORITHM_BINARYTREEPATHS_H

/*
 * 257. 二叉树的所有路径
 *  给定一个二叉树，返回所有从根节点到叶子节点的路径。
 *  说明: 叶子节点是指没有子节点的节点。
 *
 * 求解策略:
 *  1. dfs
 *  2. bfs
 */

#include <vector>
#include <string>
#include <queue>
#include "../common.h"

using namespace std;

void binaryTreePaths(TreeNode *root, string path, vector<string> &ans) {
    if (root == nullptr)
        return;
    path.append(to_string(root->val));
    if (root->left == nullptr && root->right == nullptr)
        ans.push_back(path);
    else
        path.append("->");
    binaryTreePaths(root->left, path, ans);
    binaryTreePaths(root->right, path, ans);
    path.pop_back();
}

vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans = {};
    if (root == nullptr) return ans;
    binaryTreePaths(root, "", ans);
    return ans;
}

vector<string> binaryTreePaths2(TreeNode *root) {
    vector<string> ans = {};
    if (root == nullptr) return ans;
    queue<TreeNode *> que;
    queue<string> paths;
    que.push(root);
    paths.push(string());
    while (!que.empty()) {
        int size = que.size();
        while (size--) {
            root = que.front();
            que.pop();
            string path = paths.front();
            path.append(to_string(root->val));
            paths.pop();
            TreeNode *left = root->left, *right = root->right;
            if (left == nullptr && right == nullptr) {
                ans.push_back(path);
                continue;
            }
            path.append("->");
            if (left) {
                que.push(left);
                paths.push(path);
            }
            if (right) {
                que.push(right);
                paths.push(path);
            }
        }
    }
    return ans;
}

#endif //ALGORITHM_BINARYTREEPATHS_H
