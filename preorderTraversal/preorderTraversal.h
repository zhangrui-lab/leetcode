//
// Created by 张锐 on 2021/3/5.
//

#ifndef ALGORITHM_PREORDERTRAVERSAL_H
#define ALGORITHM_PREORDERTRAVERSAL_H

/*
 * 144. 二叉树的前序遍历
 *  给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 * 1. 递归
 * 2. stack实现
 * 3. Morris 前序遍历
 *  有一种巧妙的方法可以在线性时间内，只占用常数空间来实现前序遍历。这种方法由 J. H. Morris 在 1979 年的论文「Traversing Binary Trees Simply and Cheaply」中首次提出，因此被称为 Morris 遍历。
 *  Morris 遍历的核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其前序遍历规则总结如下：
 *  新建临时节点，令该节点为 root；
 *  如果当前节点的左子节点为空，将当前节点加入答案，并遍历当前节点的右子节点；
 *  如果当前节点的左子节点不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点：
 *  如果前驱节点的右子节点为空，将前驱节点的右子节点设置为当前节点。然后将当前节点加入答案，并将前驱节点的右子节点更新为当前节点。当前节点更新为当前节点的左子节点。
 *  如果前驱节点的右子节点为当前节点，将它的右子节点重新设为空。当前节点更新为当前节点的右子节点。
 *  重复步骤 2 和步骤 3，直到遍历结束。
 *  这样我们利用 Morris 遍历的方法，前序遍历该二叉树，即可实现线性时间与常数空间的遍历。
 */

#include <stack>
#include <vector>
#include "../common.h"

void preorderTraversal(TreeNode *root, std::vector<int> &ans) {
    if (!root)
        return;
    ans.push_back(root->val);
    preorderTraversal(root->left, ans);
    preorderTraversal(root->right, ans);
}

std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> ans;
    preorderTraversal(root, ans);
    return ans;
}

std::vector<int> preorderTraversal1(TreeNode *root) {
    std::vector<int> ans;
    std::stack<TreeNode *> stk;
    auto visitAndGoLeft = [&ans, &stk](TreeNode *node) {
        while (node) {
            ans.push_back(node->val);
            stk.push(node->right);
            node = node->left;
        }
    };
    visitAndGoLeft(root);
    while (!stk.empty()) {
        root = stk.top();
        stk.pop();
        visitAndGoLeft(root);
    }
    return ans;
}

std::vector<int> preorderTraversal2(TreeNode *root) {
    std::vector<int> ans;
    auto findPrecursor = [](TreeNode *node) {
        auto precursor = node ? node->left : nullptr;
        while (precursor && precursor->right && precursor->right != node) precursor = precursor->right;
        return precursor;
    };
    TreeNode *precursor = nullptr;
    while (root) {
        precursor = findPrecursor(root);
        if (!precursor) {
            ans.push_back(root->val);
        } else if (precursor->right == nullptr) {
            ans.push_back(root->val);
            precursor->right = root;
            root = root->left;
            continue;
        } else {
            precursor->right = nullptr;
        }
        root = root->right;
    }
    return ans;
}

std::vector<int> preorderTraversal3(TreeNode *root) {
    std::vector<int> ans;
    if (root == nullptr) {
        return ans;
    }
    TreeNode *p1 = root, *p2 = nullptr;
    while (p1 != nullptr) {
        p2 = p1->left;
        if (p2 != nullptr) {
            while (p2->right != nullptr && p2->right != p1) {
                p2 = p2->right;
            }
            if (p2->right == nullptr) {
                ans.emplace_back(p1->val);
                p2->right = p1;
                p1 = p1->left;
                continue;
            } else {
                p2->right = nullptr;
            }
        } else {
            ans.emplace_back(p1->val);
        }
        p1 = p1->right;
    }
    return ans;
}


#endif //ALGORITHM_PREORDERTRAVERSAL_H
