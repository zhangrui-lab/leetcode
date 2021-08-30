//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_AVERAGEOFLEVELS_H
#define ALGORITHM_AVERAGEOFLEVELS_H

/**
 * 637. 二叉树的层平均值
 *  给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
 *
 * 求解策略:
 *  1. dfs
 *  2. bfs
 */

#include <queue>
#include <vector>
#include "../common.h"

using namespace std;


void dfs(TreeNode *root, int depth, vector<long> &sum, vector<int> &count) {
    if (root == nullptr) return;
    if (sum.size() <= depth) {
        sum.push_back(root->val);
        count.push_back(1);
    } else {
        sum[depth] += root->val;
        count[depth]++;
    }
    dfs(root->left, depth + 1, sum, count);
    dfs(root->right, depth + 1, sum, count);
}

vector<double> averageOfLevels(TreeNode *root) {
    vector<long> sum;
    vector<int> count;
    vector<double> ans;
    dfs(root, 0, sum, count);
    for (int i = 0, size = sum.size(); i < size; ++i)
        ans.push_back((double) sum[i] / count[i]);
    return ans;
}

vector<double> averageOfLevels2(TreeNode *root) {
    vector<double> ans;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size(), sum = 0, num = 0;
        while (size--) {
            num++;
            sum += que.front()->val;
            if (que.front()->left) que.push(que.front()->left);
            if (que.front()->right) que.push(que.front()->right);
            que.pop();
        }
        if (num) ans.push_back(sum / num);
    }
    return ans;
}

#endif //ALGORITHM_AVERAGEOFLEVELS_H
