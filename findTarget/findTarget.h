//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_FINDTARGET_H
#define ALGORITHM_FINDTARGET_H

/**
 * 653. 两数之和 IV - 输入 BST
 *  给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 *
 * 求解策略:
 *  1. 将层序结构转化为线性结构进行求解
 *  2. DFS+hashSet
 *  3. BFS+hashSet
 */

#include <queue>
#include <vector>
#include <unordered_set>
#include "../common.h"
#include "../morris/morris.h"

using namespace std;

bool findTarget(TreeNode *root, int k) {
    auto seq = inorder(root);
    for (int i = 0, j = seq.size() - 1; i < j; i++) {
        while (i < j && seq[i] + seq[j] > k) j--;
        if (i < j && seq[i] + seq[j] == k) return true;
    }
    return false;
}

bool dfs(TreeNode *root, int k, unordered_set<int> &nums) {
    if (root == nullptr) return false;
    bool exists = nums.count(root->val);
    nums.insert(k - root->val);
    return exists || dfs(root->left, k, nums) || dfs(root->right, k, nums);
}

bool findTarget2(TreeNode *root, int k) {
    unordered_set<int> nums;
    return dfs(root, k, nums);
}

bool findTarget3(TreeNode *root, int k) {
    unordered_set<int> set;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        if (que.front() != nullptr) {
            TreeNode *node = que.front();
            if (set.count(k - node->val))
                return true;
            set.insert(node->val);
            que.push(node->right);
            que.push(node->left);
        }
        que.pop();
    }
    return false;
}

#endif //ALGORITHM_FINDTARGET_H
