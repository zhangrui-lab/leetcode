//
// Created by 张锐 on 2021/3/19.
//

#ifndef ALGORITHM_DEEPESTLEAVESSUM_H
#define ALGORITHM_DEEPESTLEAVESSUM_H

#include "../common.h"

/*
 * 1302. 层数最深叶子节点的和
 *  给你一棵二叉树的根节点 root ，请你返回层数最深的叶子节点的和。
 *
 * 1. DFS: 任意遍历顺序
 *  记录 DFS 所到达得叶节点深度和最大深度，并依据当前节点深度和最大深度之间得关系作出相应操作：
 *      1. currDepth  == maxDepth
 *          sum += curNode->val;
 *      2. currDepth  >  maxDepth
 *          maxDepth = currDepth;
 *          sum  = curNode->val;
 *      3. currDepth  <  maxDepth
 *          return;
 *
 * 2. BFS：直接获取最后一层得节点和
 */

#include <queue>

void deepestLeavesSum(TreeNode *root, int depth, int &maxDepth, int &sum) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        if (depth == maxDepth)
            sum += root->val;
        if (depth > maxDepth) {
            maxDepth = depth;
            sum = root->val;
        }
    }
    deepestLeavesSum(root->left, depth + 1, maxDepth, sum);
    deepestLeavesSum(root->right, depth + 1, maxDepth, sum);
}

int deepestLeavesSum(TreeNode *root) {
    int sum = 0, maxDepth = 0;
    deepestLeavesSum(root, 0, maxDepth, sum);
    return sum;
}

int deepestLeavesSum2(TreeNode *root) {
    if (!root)
        return 0;
    std::queue<TreeNode *> queue;
    queue.push(root);
    int sum;
    while (!queue.empty()) {
        sum = 0;
        for (int i = 0, size = queue.size(); i < size; ++i) {
            sum += queue.front()->val;
            if (queue.front()->left)
                queue.push(queue.front()->left);
            if (queue.front()->right)
                queue.push(queue.front()->right);
            queue.pop();
        }
    }
    return sum;
}

#endif //ALGORITHM_DEEPESTLEAVESSUM_H
