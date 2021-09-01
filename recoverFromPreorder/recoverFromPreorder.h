//
// Created by Administrator on 2021/8/31.
//

#ifndef ALGORITHM_RECOVERFROMPREORDER_H
#define ALGORITHM_RECOVERFROMPREORDER_H

/**
 * 1028. 从先序遍历还原二叉树
 *  我们从二叉树的根节点 root 开始进行深度优先搜索。在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果
 *  节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。如果节点只有一个子节点，那么保证该子节点为左子节点。给出遍历输出 S，还原树并返回其根节点 root。
 *
 * 求解策略:
 *  1. 迭代前序遍历
 */

#include <deque>
#include <cctype>
#include <vector>
#include "../common.h"

using namespace std;

TreeNode *recoverFromPreorder(string traversal) {
    deque<TreeNode *> stk;
    for (int i = 0, j = 0, size = traversal.length(); i < size; i = j) {
        while (j < size && traversal[j] == '-') j++;
        int val = 0, depth = j - i, cDepth = stk.size();
        while (isalnum(traversal[j])) val = val * 10 + (traversal[j++] - '0');
        TreeNode *tmp = new TreeNode(val);
        while (!stk.empty() && stk.size() != depth) stk.pop_back();
        if (!stk.empty()) (cDepth == depth ? stk.back()->left : stk.back()->right) = tmp;
        stk.push_back(tmp);
    }
    return stk.front();
}

#endif //ALGORITHM_RECOVERFROMPREORDER_H
