//
// Created by 张锐 on 2021/1/27.
//

#ifndef ALGORITHM_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H
#define ALGORITHM_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H

/*
 * 108. 将有序数组转换为二叉搜索树
 *  将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 *  本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 *
 * 1. DFS实现
 */

#include <vector>
#include "../common.h"

TreeNode *sortedArrayToBST1(int lo, int hi, std::vector<int> &nums) {
    if (lo >= hi)
        return nullptr;
    int mid = (lo + hi) >> 1;
    TreeNode *root = new TreeNode(nums[mid], sortedArrayToBST1(lo, mid, nums), sortedArrayToBST1(mid + 1, hi, nums));
    return root;
}

TreeNode *sortedArrayToBST1(std::vector<int> &nums) {
    return sortedArrayToBST1(0, nums.size(), nums);
}

#endif //ALGORITHM_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H
