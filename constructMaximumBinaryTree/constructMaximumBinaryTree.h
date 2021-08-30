//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_CONSTRUCTMAXIMUMBINARYTREE_H
#define ALGORITHM_CONSTRUCTMAXIMUMBINARYTREE_H

/**
 * 654. 最大二叉树
 *  给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的最大二叉树定义如下：
 *      二叉树的根是数组 nums 中的最大元素。
 *      左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
 *      右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
 *      返回有给定数组 nums 构建的 最大二叉树 。
 *
 * 求解策略:
 *  1. dfs:
 *      令f(x, nums, left, right)返回序列 nums [left,right) 最大二叉树的根节点.
 *      寻找nums [left,right)中的最大元素位置pos, 为pos创建节点 root, root->left = f(x, nums, left, pos), root->right = f(x, nums, pos+1, right)
 */

#include <vector>
#include <algorithm>
#include "../common.h"

using namespace std;

TreeNode *dfs(vector<int> &nums, int left, int right) {
    if (left >= right) return nullptr;
    int pos = max_element(nums.begin() + left, nums.begin() + right) - nums.begin();
    return new TreeNode(nums[pos], dfs(nums, left, pos), dfs(nums, pos + 1, right));
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return dfs(nums, 0, nums.size());
}

#endif //ALGORITHM_CONSTRUCTMAXIMUMBINARYTREE_H
