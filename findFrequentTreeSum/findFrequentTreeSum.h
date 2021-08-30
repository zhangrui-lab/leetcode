//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_FINDFREQUENTTREESUM_H
#define ALGORITHM_FINDFREQUENTTREESUM_H

/**
 * 508. 出现次数最多的子树元素和
 *  给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
 *  你需要返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
 *
 * 求解策略:
 *  1. 蛮力: 迭代子树, 并求出所有子树可能的元素和, 返回出现次数最多者.
 *      令函数f(x)返回以x为根的子树的元素和.   f(x) = f(x->left) + f(right) + x->val; (x != nullptr)
 *                                       f(x) = 0;                              (x != nullptr)
 *  2. 优化蛮力的空间复杂度:
 *      a. Morris
 */

#include <vector>
#include <algorithm>
#include "../common.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

int findFrequentTreeSum(TreeNode *root, unordered_map<int, int> &memo) {
    if (root == nullptr)
        return 0;
    int lv = findFrequentTreeSum(root->left, memo), rv = findFrequentTreeSum(root->right, memo);
    int cv = root->val + lv + rv;
    memo[cv]++;
    return cv;
}

vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> memo;
    findFrequentTreeSum(root, memo);
    unordered_set<int> ans;
    int max = INT_MIN;
    for (auto iter = memo.cbegin(); iter != memo.cend(); iter++) {
        if (max < iter->second) {
            max = iter->second;
            ans = {iter->first};
        } else if (max == iter->second) {
            ans.insert(iter->first);
        }
    }
    return vector<int>(ans.cbegin(), ans.cend());
}

#endif //ALGORITHM_FINDFREQUENTTREESUM_H
