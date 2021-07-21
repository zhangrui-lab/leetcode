//
// Created by Administrator on 2021/7/21.
//

#ifndef ALGORITHM_POSTORDERTRAVERSAL_H
#define ALGORITHM_POSTORDERTRAVERSAL_H

/**
 * 145. 二叉树的后序遍历
 *  给定一个二叉树，返回它的后序遍历。
 *  输入: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * 输出: [3,2,1]
 *
 *
 * 求解思路:
 *  1. 递归策略: 优先访问左子树,右子树, 当左右子树访问完成时访问当前节点.
 *  2. stack迭代策略:
 *      a. 利用prev保存当前已访问节点. root只想当前迭代节点, stack保存回溯信息.
 *      b. root一直深入到最左侧节点, 当root无右侧节点或者root的右侧节点刚被访问过时, 访问root. 否则, root入stack, root=root->right
 *  3. Morris 遍历: Morris 遍历核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其后序遍历规则总结如下
 *      a. 新建临时节点，令该节点为 root；
 *      b. 如果当前节点的左子节点为空，则遍历当前节点的右子节点；
 *      c. 如果当前节点的左子节点不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点；
 *      d. 如果前驱节点的右子节点为空，将前驱节点的右子节点设置为当前节点，当前节点更新为当前节点的左子节点。
 *      e. 如果前驱节点的右子节点为当前节点，将它的右子节点重新设为空。倒序输出从当前节点的左子节点到该前驱节点这条路径上的所有节点。当前节点更新为当前节点的右子节点。
 *      f. 重复步骤 b 和步骤 c，直到遍历结束。
 *      这样我们利用 Morris 遍历的方法，后序遍历该二叉搜索树，即可实现线性时间与常数空间的遍历。
 *  4. 利用stack实现的迭代策略(当节点中存在parent指针时):
 *      a. 在以S栈顶节点为根的子树中，找到最高左侧可见叶节点. 沿途所遇节点依次入栈. 反复检查当前节点（即栈顶）尽可能向左,若有右孩子，优先入栈,然后才转至左孩子,实不得已, 才向右
 *      b. 若栈顶非当前节点之父（则必为其右兄），此时需在以其右兄为根之子树中，找到HLVFL（相当于递归深入其中）弹出栈顶（即前一节点之后继），并访问之
 */

#include <stack>
#include <vector>
#include "../common.h"

using namespace std;

void postorderTraversal(TreeNode *root, vector<int> &ans) {
    if (!root)
        return;
    postorderTraversal(root->left, ans);
    postorderTraversal(root->right, ans);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    postorderTraversal(root, ans);
    return ans;
}

vector<int> postorderTraversal2(TreeNode *root) {
    vector<int> ans;
    if (!root)
        return ans;
    stack<TreeNode *> stk;
    TreeNode *prev = nullptr;
    while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {                               // root为根的子树的最左侧节点
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (root->right == nullptr || root->right == prev) {    // root不存在右子节点或者右子节点刚已经被访问时
            ans.push_back(root->val);
            prev = root;
            root = nullptr;
        } else {
            stk.push(root);
            root = root->right;
        }
    }
    return ans;
}

vector<int> postorderTraversal3(TreeNode *root) {
    vector<int> ans;
    auto appendReverse = [](vector<int> &vec, TreeNode *node) {
        int count = 0;
        while (node != nullptr) {
            ++count;
            vec.push_back(node->val);
            node = node->right;
        }
        reverse(vec.end() - count, vec.end());
    };
    TreeNode *curr = root, *prev = nullptr;
    while (curr != nullptr) {
        prev = curr->left;
        if (prev) {
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
                continue;
            } else {
                prev->right = nullptr;
                appendReverse(ans, curr->left);
            }
        }
        curr = curr->right;
    }
    appendReverse(ans, root);
    return ans;
}

#endif //ALGORITHM_POSTORDERTRAVERSAL_H
