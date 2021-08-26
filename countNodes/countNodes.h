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
 *                                  1(1)
 *                     10(2)                              11(3)
 *             100(4)          101(5)            110(6)               111(7)
 *       1000(8)  1001(9) 1010(10) 1011(11) 1100(12)  1101(13)  1110(14)   1111(15)
 * 10000(16)  10001(17) ......
 *      树中第 h 层的节点数为: 0 ~ 2{h}       (h>0)
 *                          0              (h=0)
 *      树中第 h 层的节点号为: 2^{h} ~ 2{h+1}-1 (h>0)
 *                          1              (h=0)
 *      节点n的编号位图可以决定其定位方式: 去除最高位1后. 从根节点开始, 依次获取最高位值x, x为0时向左,x为1时向右.
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

int countNodes4(TreeNode *root) {
    if (root == nullptr) return 0;
    int height = 0;
    TreeNode *node = root;
    while (node->left) {
        height++;
        node = node->left;
    }
    auto exists = [](TreeNode *root, int height, int node) {
        for (int bits = 1 << (height - 1); bits != 0; bits >>= 1) {
            root = (bits & node) ? root->right : root->left;
        }
        return root != nullptr;
    };
    int low = 1 << height, high = (1 << (height + 1)) - 1, mid;
    while (low < high) {
        mid = (high - low + 1) / 2 + low;
        if (exists(root, height, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}


#endif //ALGORITHM_COUNTNODES_H
