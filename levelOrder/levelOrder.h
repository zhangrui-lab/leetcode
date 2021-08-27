//
// Created by Administrator on 2021/8/27.
//

#ifndef ALGORITHM_LEVELORDER_H
#define ALGORITHM_LEVELORDER_H

/**
 * 429. N 叉树的层序遍历
 *  给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
 *
 * 求解策略:
 *  1. queue
 *  2. dfs: dfs方式对数据结构进行访问时会优先深入, 我们可以在深入过程中记录下当前所访问节点的深度, 并将其放入对应层的结果集中.
 *
 *
 */

#include <queue>
#include <vector>
#include <algorithm>
#include "../common.h"

using namespace std;

vector<vector<int>> levelOrder(NTreeNode *root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;
    queue<NTreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> tmp;
        while (size--) {
            root = que.front();
            for_each(root->children.cbegin(), root->children.cend(),
                     [&que](NTreeNode *node) { if (node != nullptr) que.emplace(node); });
            tmp.emplace_back(root->val);
            que.pop();
        }
        ans.push_back(tmp);
    }
    return ans;
}


void dfs(NTreeNode *root, int level, vector<vector<int>> &ans) {
    if (root == nullptr) return;
    if (ans.size() <= level)
        ans.push_back({});
    ans[level].push_back(root->val);
    for (auto iter = root->children.begin(); iter != root->children.cend(); iter++) {
        dfs(*iter, level + 1, ans);
    }
}

vector<vector<int>> levelOrder2(NTreeNode *root) {
    vector<vector<int>> ans;
    dfs(root, 0, ans);
    return ans;
}

#endif //ALGORITHM_LEVELORDER_H
