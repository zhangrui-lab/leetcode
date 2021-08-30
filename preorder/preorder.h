//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_PREORDER_H
#define ALGORITHM_PREORDER_H

/**
 * 589. N 叉树的前序遍历
 *  给定一个 N 叉树，返回其节点值的 前序遍历 。N 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。
 * 进阶：递归法很简单，你可以使用迭代法完成此题吗?
 *
 * 求解策略:
 *  1. 递归
 *  2. stack: stack替换递归回溯
 */

#include <vector>
#include <stack>
#include "../common.h"

using namespace std;

void preorder(NTreeNode *root, vector<int> &ans) {
    if (root == nullptr) return;
    ans.push_back(root->val);
    for (auto iter = root->children.begin(); iter != root->children.end(); iter++)
        preorder(*iter, ans);
}

vector<int> preorder(NTreeNode *root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

vector<int> preorder2(NTreeNode *root) {
    vector<int> ans;
    if (root == nullptr) return ans;
    stack<NTreeNode *> stk;
    auto visitGoLeft = [&stk, &ans](NTreeNode *node) {
        while (node) {
            ans.push_back(node->val);
            if (!node->children.empty())
                for (auto iter = node->children.rbegin(); iter != node->children.rend() - 1; iter++)
                    stk.push(*iter);
            node = node->children.empty() ? nullptr : node->children.front();
        }
    };
    visitGoLeft(root);
    while (!stk.empty()) {
        root = stk.top();
        stk.pop();
        visitGoLeft(root);
    }
    return ans;
}

vector<int> preorder3(NTreeNode *root) {
    vector<int> ans;
    if (root == nullptr) return ans;
    stack<NTreeNode *> stk;
    stk.push(root);
    while (!stk.empty()) {
        root = stk.top();
        stk.pop();
        for (auto iter = root->children.rbegin(); iter != root->children.rend(); iter++)
            stk.push(*iter);
        ans.push_back(root->val);
    }
    return ans;
}

#endif //ALGORITHM_PREORDER_H
