//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_FINDBOTTOMLEFTVALUE_H
#define ALGORITHM_FINDBOTTOMLEFTVALUE_H

/**
 * 513. 找树左下角的值
 *  给定一个二叉树的 根节点 root，请找出该二叉树的 最底层最左边节点的值。
 *  假设二叉树中至少有一个节点。
 *
 * 求解策略:
 *  1. 层序遍历: 用prev记录当前所在层的第一个输出节点. 当遍历结束时返回prev.
 *  2. 前序遍历: height记录当前深度,maxHeight记录最大深度. 当height > maxHeight时, 使用节点prev记录. 当遍历结束时返回prev (遍历策略为先访问当前节点, 再访问右子节点, 最后访问左子节点. )
 *  3. morris前序
 */

#include <queue>
#include <cassert>
#include "../common.h"

using namespace std;

int findBottomLeftValue(TreeNode *root) {
    assert(root != nullptr);
    TreeNode *prev = nullptr;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        while (size--) {
            if (prev == nullptr) prev = que.front();
            if (que.front()->left) que.push(que.front()->left);
            if (que.front()->right) que.push(que.front()->right);
            que.pop();
        }
        prev = que.empty() ? prev : nullptr;
    }
    return prev->val;
}

void dfs(TreeNode *root, int height, int &maxHeight, int &prev) {
    if (root == nullptr) return;
    if (height > maxHeight) {
        maxHeight = height;
        prev = root->val;
    }
    dfs(root->left, height + 1, maxHeight, prev);
    dfs(root->right, height + 1, maxHeight, prev);
}

int findBottomLeftValue2(TreeNode *root) {
    int maxHeight = -1, prev = -1;
    dfs(root, 0, maxHeight, prev);
    return prev;
}

#endif //ALGORITHM_FINDBOTTOMLEFTVALUE_H
