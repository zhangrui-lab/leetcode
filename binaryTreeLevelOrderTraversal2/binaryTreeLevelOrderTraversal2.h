//
// Created by 张锐 on 2021/1/27.
//

#ifndef ALGORITHM_BINARYTREELEVELORDERTRAVERSAL2_H
#define ALGORITHM_BINARYTREELEVELORDERTRAVERSAL2_H

/*
 * 107. 二叉树的层序遍历 II
 *  给定一个二叉树，返回其节点值自底向上的层序遍历。（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 */

#include <vector>
#include <queue>
#include "../common.h"

std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    if (!root)
        return ans;
    std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
        std::vector<int> tmp;
        int size = queue.size();
        while (size--) {
            root = queue.front();
            queue.pop();
            tmp.push_back(root->val);
            if (root->left)
                queue.push(root->left);
            if (root->right)
                queue.push(root->right);
        }
        ans.push_back(tmp);
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

#endif //ALGORITHM_BINARYTREELEVELORDERTRAVERSAL2_H
