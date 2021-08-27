//
// Created by Administrator on 2021/8/27.
//

#ifndef ALGORITHM_PATHSUM3_H
#define ALGORITHM_PATHSUM3_H

/**
 * 437. 路径总和 III
 *  给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的路径的数目。
 *  路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 *
 * 求解策略:
 *  遍历树, 每达到一个节点时查看已当前节点为结尾的路径的所有可能和为targetSum的数量.
 *  1. 蛮力策略: 获取所有可能的路径并返回总和为targetSum的部分.
 *      dfs遍历树结构, 记录从root到curnode的路径. 当从节点curnode返回时, 计算以curnode为路径结尾节点的所有可能路径并返回.
 *  2. 蛮力优化: 前缀和策略(将前缀和保存在一个字典中, 每到达一个节点时, 查看字典中是否存在targetSum-curnode->val的元素);
 */

#include <set>
#include <deque>
#include "../common.h"

using namespace std;

int pathSum(TreeNode *root, int targetSum, vector<TreeNode *> path = {}) {
    if (root == nullptr) return 0;
    int sum = 0, num = 0;
    path.emplace_back(root);
    num += pathSum(root->left, targetSum, path);
    num += pathSum(root->right, targetSum, path);
    for (auto iter = path.rbegin(); iter != path.rend(); iter++) {
        sum += (*iter)->val;
        num += (sum == targetSum);
    }
    return num;
}

int pathSum2(TreeNode *root, int targetSum, int pSum, multiset<int> &memo) {
    if (root == nullptr) return 0;
    pSum += root->val;
    int num = memo.count(pSum - targetSum) + (pSum == targetSum ? 1 : 0);
    auto iter = memo.insert(pSum);
    num += pathSum2(root->left, targetSum, pSum, memo);
    num += pathSum2(root->right, targetSum, pSum, memo);
    memo.erase(iter);
    return num;
}

int pathSum2(TreeNode *root, int targetSum) {
    multiset<int> memo;
    return pathSum2(root, targetSum, 0, memo);
}

#endif //ALGORITHM_PATHSUM3_H

