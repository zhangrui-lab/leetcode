//
// Created by 张锐 on 2021/1/27.
//

#ifndef ALGORITHM_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H
#define ALGORITHM_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H

/*
 * 106. 从中序与后序遍历序列构造二叉树
 *  根据一棵树的中序遍历与后序遍历构造二叉树。
 *  注意:
 *      你可以假设树中没有重复的元素。
 *
 * 思路：
 *  中序遍历序列
 *      【左子树】 【跟节点】 【右子树】
 *  后序遍历序列
 *      【左子树】 【右子树】 【跟节点】
 *  根据后续遍历定位当前遍历序列的很节点，根据中序遍历序列去判定左右子树的节点数目。
 * 1. DFS
 *  postOrder:[pl, pr); iOrder: [il, ir);
 *  root = new Node(postOrder[pr]); find postOrder[pr] position in iOrder p;
 *  leftTree nodes: p-il; rightTree nodes: ir-p;
 * 2. 迭代
 */

#include "../common.h"
#include <vector>
#include <unordered_map>
#include <stack>

TreeNode *constructFromInOrderAndPostOrder(std::vector<int> &inorder, std::vector<int> &postorder) {
    if (postorder.size() == 0) {
        return nullptr;
    }
    auto root = new TreeNode(postorder[postorder.size() - 1]);
    auto s = std::stack<TreeNode *>();
    s.push(root);
    int inorderIndex = inorder.size() - 1;
    for (int i = int(postorder.size()) - 2; i >= 0; i--) {
        int postorderVal = postorder[i];
        auto node = s.top();
        if (node->val != inorder[inorderIndex]) {
            node->right = new TreeNode(postorderVal);
            s.push(node->right);
        } else {
            while (!s.empty() && s.top()->val == inorder[inorderIndex]) {
                node = s.top();
                s.pop();
                inorderIndex--;
            }
            node->left = new TreeNode(postorderVal);
            s.push(node->left);
        }
    }
    return root;
}

#endif //ALGORITHM_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H
