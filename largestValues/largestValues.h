//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_LARGESTVALUES_H
#define ALGORITHM_LARGESTVALUES_H

/**
 * 515. 在每个树行中找最大值
 *  给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 *
 * 求解策略:
 *  1. 层序遍历: 获取并记录当前所在层的最大值.
 *  2. dfs: 遍历过程中记录当前节点的深度, 和当前深度所具有的最大值, 使用当前值更新对应深度的最大值.
 */

#include <queue>
#include "../common.h"

using namespace std;

vector<int> largestValues(TreeNode *root) {
    vector<int> ans;
    queue<TreeNode *> que;
    if (root == nullptr) return ans;
    que.push(root);
    while (!que.empty()) {
        int size = que.size(), lmax = INT_MIN;
        while (size--) {
            lmax = max(lmax, que.front()->val);
            if (que.front()->left) que.push(que.front()->left);
            if (que.front()->right) que.push(que.front()->right);
            que.pop();
        }
        ans.push_back(lmax);
    }
    return ans;
}

void dfs(TreeNode *root, int height, vector<int> &maxNums) {
    if (root == nullptr) return;
    if (maxNums.size() == height) maxNums.push_back(root->val);
    else maxNums[height] = max(maxNums[height], root->val);
    dfs(root->left, height + 1, maxNums);
    dfs(root->right, height + 1, maxNums);
}

vector<int> largestValues2(TreeNode *root) {
    vector<int> maxNums;
    dfs(root, 0, maxNums);
    return maxNums;
}

#endif //ALGORITHM_LARGESTVALUES_H
