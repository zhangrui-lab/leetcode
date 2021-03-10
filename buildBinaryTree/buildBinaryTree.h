//
// Created by 张锐 on 2021/3/10.
//

#ifndef ALGORITHM_BUILDBINARYTREE_H
#define ALGORITHM_BUILDBINARYTREE_H

/*
 * 剑指 Offer 07. 重建二叉树
 *  输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如，给出
 *  前序遍历 preorder = [3,9,20,15,7]
 *  中序遍历 inorder  = [9,3,15,20,7]
 *  返回如下的二叉树：
 *       3
 *      / \
 *     9  20
 *       /  \
 *     15    7
 *
 * 1. 递归实现
 * 2. 迭代
 *  前序遍历中的连续节点u,v所存在的情况:
 *      1. u 存在左子节点时，则v为其左子节点。
 *      2. u 不存在左子节点且存在右子节点时，则v为其右子节点。
 *      3. u 不存在左子节点且不存在右子节点时，则v为其某个具有右子节点的祖先节点的右子节点。
 *  算法流程：
 *      我们用一个栈和一个指针辅助进行二叉树的构造。初始时栈中存放了根节点（前序遍历的第一个节点），指针指向中序遍历的第一个节点；
 *      我们依次枚举前序遍历中除了第一个节点以外的每个节点。如果 index 恰好指向栈顶节点，那么我们不断地弹出栈顶节点并向右移动 index，并将当前节点作为最后一个弹出的节点的右儿子；如果 index 和栈顶节点不同，我们将当前节点作为栈顶节点的左儿子；
 *      无论是哪一种情况，我们最后都将当前的节点入栈。
 */

#include <vector>
#include <stack>
#include "../common.h"

TreeNode *buildBinaryTree(int plo, int phi, int ilo, int ihi, std::vector<int> &preorder, std::vector<int> &inorder) {
    if (plo >= phi || ilo >= ihi)
        return nullptr;
    int i;
    for (i = ilo; i < ihi && inorder[i] != preorder[plo]; ++i);
    return new TreeNode(preorder[plo],
                        buildBinaryTree(plo + 1, plo + i - ilo + 1, ilo, i, preorder, inorder),
                        buildBinaryTree(plo + i - ilo + 1, phi, i + 1, ihi, preorder, inorder)
    );
}

TreeNode *buildBinaryTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    return buildBinaryTree(0, preorder.size(), 0, inorder.size(), preorder, inorder);
}


TreeNode *buildBinaryTree1(std::vector<int> &preorder, std::vector<int> &inorder) {
    if (preorder.empty())
        return nullptr;
    TreeNode *root = new TreeNode(preorder[0]);
    std::stack<TreeNode *> stk;
    stk.push(root);
    int inorderIndex = 0;
    for (int i = 1; i < preorder.size(); ++i) {
        int preorderVal = preorder[i];
        TreeNode *node = stk.top();
        if (node->val != inorder[inorderIndex]) {
            node->left = new TreeNode(preorderVal);
            stk.push(node->left);
        } else {
            while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                node = stk.top();
                stk.pop();
                ++inorderIndex;
            }
            node->right = new TreeNode(preorderVal);
            stk.push(node->right);
        }
    }
    return root;
}

#endif //ALGORITHM_BUILDBINARYTREE_H
