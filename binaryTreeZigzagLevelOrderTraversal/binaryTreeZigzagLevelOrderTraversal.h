//
// Created by 47302 on 2021/1/26.
//

#ifndef ALGORITHM_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
#define ALGORITHM_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H

/*
 * 103. 二叉树的锯齿形层序遍历
 *  给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 */

#include <queue>
#include <vector>
#include <algorithm>
#include "../common.h"

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
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
            if (level % 2 == 0)
                std::reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            level = node.first;
            tmp.clear();
            tmp.push_back(node.second->val);
        }
    }
    if (level % 2 == 0)
        std::reverse(tmp.begin(), tmp.end());
    ans.push_back();
    return ans;
}

#endif //ALGORITHM_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
