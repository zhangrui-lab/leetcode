//
// Created by Administrator on 2021/8/31.
//

#ifndef ALGORITHM_VERTICALTRAVERSAL_H
#define ALGORITHM_VERTICALTRAVERSAL_H

/**
 * 987. 二叉树的垂序遍历
 *  给你二叉树的根结点 root ，请你设计算法计算二叉树的 垂序遍历 序列。对位于 (row, col) 的每个结点而言，其左右子结点分别位于 (row + 1, col - 1) 和 (row + 1, col + 1) 。树的根结点位于 (0, 0) 。
 *  二叉树的 垂序遍历 从最左边的列开始直到最右边的列结束，按列索引每一列上的所有结点，形成一个按出现位置从上到下排序的有序列表。如果同行同列上有多个结点，则按结点的值从小到大进行排序。返回二叉树的 垂序遍历 序列。
 *
 * 求解策略:
 *  1. map+priority_queue
 */

#include <map>
#include <vector>
#include <queue>
#include "../common.h"

using namespace std;

class Solution {
public:
    struct Node {
        int x, y, val;

        Node() {}

        Node(int a, int b, int c) : x(a), y(b), val(c) {}

        bool operator<(Node node) const {
            if (y != node.y) return y > node.y;
            else if (x != node.x) return x > node.x;
            return val > node.val;
        }
    };

    map<int, priority_queue<Node> > ss;
    vector<vector<int>> ans;

    void dfs(int x, int y, TreeNode *root) {
        if (!root) return;
        ss[y].push({x, y, root->val});
        dfs(x + 1, y - 1, root->left);
        dfs(x + 1, y + 1, root->right);
        return;
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        if (!root) return ans;
        dfs(0, 0, root);
        for (auto &[x, y] : ss) {
            ans.push_back(vector<int>());
            while (!y.empty()) {
                ans.back().push_back(y.top().val);
                y.pop();
            }
        }
        return ans;
    }
};

#endif //ALGORITHM_VERTICALTRAVERSAL_H

