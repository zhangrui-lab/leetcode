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
 *  中序遍历 inorder = [9,3,15,20,7]
 *  返回如下的二叉树：
 *       3
 *      / \
 *     9  20
 *       /  \
 *     15    7
 */

#include <vector>
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


#endif //ALGORITHM_BUILDBINARYTREE_H
