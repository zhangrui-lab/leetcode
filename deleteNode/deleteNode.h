//
// Created by Administrator on 2021/8/27.
//

#ifndef ALGORITHM_DELETENODE_H
#define ALGORITHM_DELETENODE_H

/**
 * 450. 删除二叉搜索树中的节点
 *  给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 *  一般来说，删除节点可分为两个步骤： 首先找到需要删除的节点； 如果找到了，删除它。
 *  说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
 *
 * 求解策略:
 *  利用二分查找策略找到所需要删除的节点 p.
 *      若不存在子节点, 直接删除p;
 *      若p只存在一个子节点x时, 用x替换p即可.
 *      若p只存在一个子节点x时,则找到p的中序遍历序列的直接后继元素x. 交换p与x, 删除x;
 */

#include <algorithm>
#include "../common.h"

using namespace std;

TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root) return nullptr;
    if (root->val == key) {
        if (!root->right) {
            TreeNode *tmp = root;
            root = root->left;
            delete tmp;
            return root;
        }
        if (!root->left) {
            TreeNode *tmp = root;
            root = root->right;
            delete tmp;
            return root;
        } else {
            TreeNode *nex = root->right;
            while (nex->left)nex = nex->left;
            nex->left = root->left;
            TreeNode *tmp = root;
            root = root->right;
            delete tmp;
            return root;
        }
    }
    if (key < root->val) root->left = deleteNode(root->left, key);
    if (key > root->val) root->right = deleteNode(root->right, key);
    return root;
}

#endif //ALGORITHM_DELETENODE_H
