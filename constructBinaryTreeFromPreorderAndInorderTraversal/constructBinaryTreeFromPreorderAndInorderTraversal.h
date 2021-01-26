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
 *
 */

#include "../common.h"
#include <std::vector>
#include <std::unordered_map>

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

#endif //ALGORITHM_CONSTRUCTBINARYTREEFROMpreOrderANDinOrderTRAVERSAL_H
