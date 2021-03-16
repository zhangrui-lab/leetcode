//
// Created by 张锐 on 2021/3/16.
//

#ifndef ALGORITHM_GETMINIMUMDIFFERENCE_H
#define ALGORITHM_GETMINIMUMDIFFERENCE_H

/*
 * 530. 二叉搜索树的最小绝对差
 *  给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。(树中至少有 2 个节点。)
 * eg:
 *  输入：
 *  1
 *   \
 *    3
 *   /
 *  2
 *  输出：1
 *
 * 解释：最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 *
 *
 * 1. 中序遍历获取所有节点，找出其中差值最小者。
 * 2. 基于递归
 * 3. 基于迭代
 */

#include "../common.h"
#include <vector>
#include <stack>
#include "../minDiffInBST/minDiffInBST.h"   // 题解相同

void getMinimumDifference(TreeNode *root, std::vector<int> &nums) {
    if (!root)
        return;
    getMinimumDifference(root->left, nums);
    nums.push_back(root->val);
    getMinimumDifference(root->right, nums);
}

int getMinimumDifference(TreeNode *root) {
    std::vector<int> nums;
    getMinimumDifference(root, nums);
    int minDiff = INT_MAX;
    for (int i = 1, n = nums.size(); i < n; ++i) {
        if (minDiff > std::abs(nums[i] - nums[i - 1]))
            minDiff = std::abs(nums[i] - nums[i - 1]);
    }
    return minDiff;
}


void getMinimumDifference2(TreeNode *root, int &prev, int &min) {
    if (!root)
        return;
    getMinimumDifference2(root->left, prev, min);
    if (prev != -1)
        min = std::min(std::abs(root->val - prev), min);
    prev = root->val;
    getMinimumDifference2(root->right, prev, min);
}

int getMinimumDifference2(TreeNode *root) {
    int min = INT_MAX, pre = -1;
    getMinimumDifference2(root, pre, min);
    return min;
}

int getMinimumDifference3(TreeNode *root) {
    std::stack<TreeNode *> stk;
    int min = INT_MAX, prev = -1;
    auto goLeft = [&stk](TreeNode *node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    };
    goLeft(root);
    while (!stk.empty()) {
        root = stk.top();
        stk.pop();
        if (prev != -1)
            min = std::min(std::abs(prev - root->val), min);
        prev = root->val;
        goLeft(root->right);
    }
    return min;
}

#endif //ALGORITHM_GETMINIMUMDIFFERENCE_H
