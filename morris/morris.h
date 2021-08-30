//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_MORRIS_H
#define ALGORITHM_MORRIS_H


/**
 * Morris 遍历算法
 *
 * 树的遍历策略:
 *  1. 前序遍历: curr->left->right(对节点curr, 先访问当前节点, 再访问左子树节点, 最后访问右子树节点)
 *  2. 中序遍历: left->curr->right(对节点curr, 先访问左子树节点, 再访问当前节点, 最后访问右子树节点)
 *  3. 后序遍历: left->right->curr(对节点curr, 先访问左子树节点, 再访问右子树节点, 最后访问当前节点)
 *
 * Morris 遍历算法基本思路:
 *  1. 寻找prev节点:
 *      a. 当前节点不存在左子树, prev = nullptr.
 *      b. 当前节点存在左子树, prev 为当前节点的左子树的最右侧且右子节点不为curr节点的节点.
 *  2. 对于当前节点curr, 选找到前驱节点prev
 *      a. prev == nullptr                  (左子树为空)
 *      b. prev && prev->right == curr      (左子树已访问完成)
 *      c. prev && prev->right == nullptr   (左子树未访问)
 *
 * 前序遍历:
 *  对上述2步. 若2.a: 访问当前节点, curr=curr->right; 若2.b: prev->right=nullptr, curr=curr->right;  若2.c: 访问当前节点, 设置 prev->right=curr, curr=curr->left;
 * 中序遍历:
 *  对上述2步. 若2.a: 访问当前节点,curr=curr->right; 若2.b: 访问当前节点,  prev->right=nullptr, curr=curr->right;  若2.c: 设置prev->right=curr, curr=curr->left;
 * 后续遍历:
 *  对上述2步. 若2.a: curr=curr->right; 若2.b: 逆序输出curr->left 到 prev 的路径. prev->right=nullptr, curr=curr->right;  若2.c: 设置prev->right=curr, curr=curr->left;
 */

#endif //ALGORITHM_MORRIS_H

#include <list>
#include <vector>
#include <algorithm>
#include "../common.h"

using namespace std;

TreeNode *inorderPrev(TreeNode *curr) {
    TreeNode *prev = curr->left;
    while (prev && prev->right && prev->right != curr)
        prev = prev->right;
    return prev;
}

vector<int> preorder(TreeNode *root) {
    vector<int> ans;
    TreeNode *prev = nullptr;
    while (root != nullptr) {
        prev = inorderPrev(root);
        if (prev == nullptr) {
            ans.push_back(root->val);
            root = root->right;
            continue;
        }
        if (prev->right == root) {
            prev->right = nullptr;
            root = root->right;
        } else if (prev->right == nullptr) {
            ans.push_back(root->val);
            prev->right = root;
            root = root->left;
        }
    }
    return ans;
}

vector<int> inorder(TreeNode *root) {
    vector<int> ans;
    TreeNode *prev = nullptr;
    while (root != nullptr) {
        prev = inorderPrev(root);
        if (prev == nullptr || prev->right == root) {
            ans.push_back(root->val);
            if (prev) prev->right = nullptr;
            root = root->right;
            continue;
        }
        prev->right = root;
        root = root->left;
    }
    return ans;
}

vector<int> postorder(TreeNode *root) {
    vector<int> ans;
    TreeNode *curr = root, *prev = nullptr;
    auto reverseOutput = [&ans](TreeNode *node) {
        int num = 0;
        while (node) {
            num++;
            ans.push_back(node->val);
            node = node->right;
        }
        reverse(ans.end() - num, ans.end());
    };
    while (curr != nullptr) {
        prev = inorderPrev(curr);
        if (prev && prev->right == nullptr) {
            prev->right = curr;
            curr = curr->left;
            continue;
        }
        if (prev && prev->right == curr) {
            prev->right = nullptr;
            reverseOutput(curr->left);
        }
        curr = curr->right;
    }
    reverseOutput(root);
    return ans;
}
