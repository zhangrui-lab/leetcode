//
// Created by 47302 on 2021/1/26.
//

#ifndef ALGORITHM_BINARYTREELEVELORDERTRAVERSAL_H
#define ALGORITHM_BINARYTREELEVELORDERTRAVERSAL_H

/*
 * 102. 二叉树的层序遍历
 *  给你一个二叉树，请你返回其按层序遍历得到的节点值。（即逐层地，从左到右访问所有节点）。
 */

#include "../common.h"
#include <vector>
#include <queue>
#include <utility>

std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    if (!root)
        return ans;
    std::queue<std::pair<int, TreeNode *>> queue;
    queue.push({1, root});
    std::vector<int> tmp;
    int level = 1;
    while (!queue.empty()) {
        std::pair<int, TreeNode *> node = queue.front();
        queue.pop();
        if (node.second->left)
            queue.push({node.first + 1, node.second->left});
        if (node.second->right)
            queue.push({node.first + 1, node.second->right});
        if (level == node.first) {
            tmp.push_back(node.second->val);
        } else {
            ans.push_back(tmp);
            level = node.first;
            tmp.clear();
            tmp.push_back(node.second->val);
        }
    }
    ans.push_back(tmp);
    return ans;
}

#endif //ALGORITHM_BINARYTREELEVELORDERTRAVERSAL_H
