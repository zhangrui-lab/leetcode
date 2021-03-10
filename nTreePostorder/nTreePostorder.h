//
// Created by 张锐 on 2021/3/10.
//

#ifndef ALGORITHM_NTREEPOSTORDER_H
#define ALGORITHM_NTREEPOSTORDER_H

/*
 * 590. N 叉树的后序遍历
 *  给定一个 N 叉树，返回其节点值的后序遍历 。
 *
 * 1. 递归
 * 2. 迭代
 */

#include <stack>
#include <vector>
#include "../common.h"

void nTreePostorder(GNode *root, std::vector<int> &ans) {
    if (!root)
        return;
    for (int i = 0, n = root->neighbors.size(); i < n; ++i)
        nTreePostorder(root->neighbors[i], ans);
    ans.push_back(root->val);
}

std::vector<int> nTreePostorder(GNode *root) {
    std::vector<int> ans;
    nTreePostorder(root, ans);
    return ans;
}

std::vector<int> nTreePostorder1(GNode *root) {
    std::vector<int> ve;
    if (!root) return ve;
    std::stack<GNode *> st;
    st.push(root);
    while (!st.empty()) {
        GNode *node = st.top();
        st.pop();
        if (node) {
            ve.emplace_back(node->val);
            std::vector<GNode *> chs = node->neighbors;
            for (int i = 0, size = chs.size(); i < size; i++) {
                GNode *n = chs[i];
                if (n) st.push(n);
            }
        }
    }
    std::reverse(ve.begin(), ve.end());
    return ve;
}

#endif //ALGORITHM_NTREEPOSTORDER_H
