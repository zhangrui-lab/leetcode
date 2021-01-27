//
// Created by 47302 on 2021/1/26.
//

#ifndef ALGORITHM_CONSTRUCTBINARYTREEFROMpreOrderANDinOrderTRAVERSAL_H
#define ALGORITHM_CONSTRUCTBINARYTREEFROMpreOrderANDinOrderTRAVERSAL_H

/*
 * 105. 从前序与中序遍历序列构造二叉树
 *  根据一棵树的前序遍历与中序遍历构造二叉树。
 * 注意:
 *  你可以假设树中没有重复的元素。
 *
 * 思路:
 *  前序遍历序列
 *      [ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]
 *  中序遍历序列
 *      [ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
 *
 * 1. DFS
 * 2. 迭代
 */

#include "../common.h"
#include <stack>
#include <vector>
#include <unordered_map>

TreeNode *buildTree(const std::vector<int> &preOrder, const std::vector<int> &inOrder, int pl, int pr,
                    int il, int ir, std::unordered_map<int, int> &index) {
    if (pl > pr) {
        return nullptr;
    }
    // 前序遍历中的第一个节点就是根节点
    int pRoot = pl;
    // 在中序遍历中定位根节点
    int iRoot = index[preOrder[pRoot]];
    // 先把根节点建立出来
    TreeNode *root = new TreeNode(preOrder[pRoot]);
    // 得到左子树中的节点数目
    int left = iRoot - il;
    // 递归地构造左子树，并连接到根节点
    // 先序遍历中「从 左边界+1 开始的 left」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
    root->left = buildTree(preOrder, inOrder, pl + 1, pl + left, il, iRoot - 1, index);
    // 递归地构造右子树，并连接到根节点
    // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
    root->right = buildTree(preOrder, inOrder, pl + left + 1, pr, iRoot + 1, ir, index);
    return root;
}

TreeNode *buildTree(std::vector<int> &preOrder, std::vector<int> &inOrder) {
    std::unordered_map<int, int> index;
    int n = preOrder.size();
    // 构造哈希映射，帮助我们快速定位根节点
    for (int i = 0; i < n; ++i)
        index[inOrder[i]] = i;
    return buildTree(preOrder, inOrder, 0, n - 1, 0, n - 1, index);
}

TreeNode *buildTree2(std::vector<int> &preOrder, std::vector<int> &inOrder) {
    if (!preOrder.size())
        return nullptr;
    TreeNode *root = new TreeNode(preOrder[0]);
    std::stack<TreeNode *> stk;
    stk.push(root);
    int index = 0;
    for (int i = 1; i < preOrder.size(); ++i) {
        int val = preOrder[i];
        TreeNode *node = stk.top();
        // 当前节点为左子节点时
        if (node->val != inOrder[index]) {
            node->left = new TreeNode(val);
            stk.push(node->left);
        } else {    // 已到达最左侧节点时。寻找左子树的第一个非最左侧路径节点
            while (!stk.empty() && stk.top()->val == inOrder[index]) {
                node = stk.top();
                stk.pop();
                ++index;
            }
            node->right = new TreeNode(val);
            stk.push(node->right);
        }
    }
    return root;
}

#endif //ALGORITHM_CONSTRUCTBINARYTREEFROMpreOrderANDinOrderTRAVERSAL_H
