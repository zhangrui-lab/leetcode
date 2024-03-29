//
// Created by Administrator on 2021/7/28.
//

#ifndef ALGORITHM_BSTITERATOR_H
#define ALGORITHM_BSTITERATOR_H

/**
 * 173. 二叉搜索树迭代器
 *  实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
 *  BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
 *  boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
 *  int next()将指针向右移动，然后返回指针处的数字。
 *  注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。
 *
 * 求解策略:
 *  1. stack
 *  2. 获取并保存完整中序遍历序列
 */

#include <stack>
#include "../common.h"

using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        goLeft(root);
    }

    int next() {
        assert(!stk.empty());
        TreeNode *node = stk.top();
        stk.pop();
        goLeft(node->right);
        return node->val;
    }

    bool hasNext() {
        return !stk.empty();
    }

private:
    stack<TreeNode *> stk;

    void goLeft(TreeNode *node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
};

class BSTIterator2 {
private:
    void inorder(TreeNode *root, vector<int> &res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    vector<int> arr;
    int idx;
public:
    BSTIterator2(TreeNode *root) : idx(0), arr(inorderTraversal(root)) {}

    int next() {
        return arr[idx++];
    }

    bool hasNext() {
        return (idx < arr.size());
    }
};


#endif //ALGORITHM_BSTITERATOR_H
