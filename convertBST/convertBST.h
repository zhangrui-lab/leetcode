//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_CONVERTBST_H
#define ALGORITHM_CONVERTBST_H

/**
 * 538. 把二叉搜索树转换为累加树
 *  给出二叉搜索树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
 *  提醒一下，二叉搜索树满足下列约束条件：
 *      节点的左子树仅包含键 小于 节点键的节点。
 *      节点的右子树仅包含键 大于 节点键的节点。
 *      左右子树也必须是二叉搜索树。
 *
 * 求解策略:
 *  1. 中序遍历的后缀和
 *  2. dfs:
 *      a. 函数f(x)返回以x为根的子树的元素之和.    f(x)=x->val+f(x->left)+f(x->right); (x != nullptr)
 *                                           f(x) = 0;                           (x == nullptr)
 *      b. 二叉搜索树中, 对任意节点x, 比x大的节点包括
 *          b1. 其右子树中节点
 *          b2. 大于将其作为左子树中节点的第一个节点的节点.
 */

#include "../common.h"

using namespace std;


void dfs(TreeNode *root, int &suffixSum) {
    if (root == nullptr) return;
    dfs(root->right, suffixSum);
    suffixSum = root->val = root->val + suffixSum;
    dfs(root->left, suffixSum);
}

TreeNode *convertBST(TreeNode *root) {
    int suffixSum = 0;
    dfs(root, suffixSum);
    return root;
}

int dfs2(TreeNode *root, int pSum) {
    if (root == nullptr) return 0;
    int rsum = dfs2(root->right, pSum), lsum = dfs2(root->left, pSum + rsum + root->val), sum = root->val + rsum + lsum;
    root->val = root->val + rsum + pSum;
    return sum;
}

TreeNode *convertBST2(TreeNode *root) {
    dfs2(root, 0);
    return root;
}

#endif //ALGORITHM_CONVERTBST_H
