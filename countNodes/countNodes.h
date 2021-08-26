//
// Created by Administrator on 2021/8/25.
//

#ifndef ALGORITHM_COUNTNODES_H
#define ALGORITHM_COUNTNODES_H

/*
 * 222. 完全二叉树的节点个数
 *  给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 *  完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
 *
 * 求解策略:
 *  1. 图遍历: dfs, bfs, stack替换迭代等...
 *  2. 二分查找策略+位结构:
 *      a. 完整树的middle节点: root右子节点的最左侧节点.
 *      b. 查看树的middle节点是否高度为树高, 若为树高, 则在其右子树进行迭代, 若不为树高, 则在其左子树中进行迭代.
 */

#include "../common.h"
#include <cmath>
#include <queue>

using namespace std;

void countNodes(TreeNode *root, int &count) {
    if (root == nullptr)
        return;
    count++;
    countNodes(root->left, count);
    countNodes(root->right, count);
}

int countNodes(TreeNode *root) {
    int count = 0;
    countNodes(root, count);
    return count;
}

int countNodes2(TreeNode *root) {
    int count = 0;
    if (root == nullptr) return count;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        count += size;
        while (size--) {
            if (que.front()->left)
                que.push(que.front()->left);
            if (que.front()->right)
                que.push(que.front()->right);
            que.pop();
        }
    }
    return count;
}

bool exists(TreeNode *root, int level, int k) {
    int bits = 1 << (level - 1);
    TreeNode *node = root;
    while (node != nullptr && bits > 0) {
        if (!(bits & k)) {
            node = node->left;
        } else {
            node = node->right;
        }
        bits >>= 1;
    }
    return node != nullptr;
}

int countNodes3(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int level = 0;
    TreeNode *node = root;
    while (node->left != nullptr) {
        level++;
        node = node->left;
    }
    int low = 1 << level, high = (1 << (level + 1)) - 1;
    while (low < high) {
        int mid = (high - low + 1) / 2 + low;
        if (exists(root, level, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

#endif //ALGORITHM_COUNTNODES_H
