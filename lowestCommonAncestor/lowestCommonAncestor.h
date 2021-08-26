//
// Created by Administrator on 2021/8/26.
//

#ifndef ALGORITHM_LOWESTCOMMONANCESTOR_H
#define ALGORITHM_LOWESTCOMMONANCESTOR_H

/**
 * 235. 二叉搜索树的最近公共祖先
 *  给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 *  百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 *
 * 求解策略:
 *  1. 使用两个容器保存从root到节点p,q的路径, 求p与q中相等的节点.
 */

#include "../common.h"
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

void getPaths(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode *> path,
              pair<vector<TreeNode *>, vector<TreeNode *>> &paths) {
    path.push_back(root);
    if (root == p || root == q) {
        (paths.first.empty() ? paths.first : paths.second) = path;
    }
    if (root->left) {
        getPaths(root->left, p, q, path, paths);
    }
    if (root->right) {
        getPaths(root->right, p, q, path, paths);
        path.pop_back();
    }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    pair<vector<TreeNode *>, vector<TreeNode *>> paths = {};
    getPaths(root, p, q, {}, paths);
    for (int i = min(paths.first.size(), paths.second.size()) - 1; i >= 0; --i) {
        if (paths.first[i] == paths.second[i])
            return paths.first[i];
    }
    return root;
}

vector<TreeNode *> getBinPath(TreeNode *root, TreeNode *target) {
    vector<TreeNode *> path;
    TreeNode *node = root;
    while (node != target) {
        path.push_back(node);
        if (target->val < node->val) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    path.push_back(node);
    return path;
}


TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> path_p = getBinPath(root, p);
    vector<TreeNode *> path_q = getBinPath(root, q);
    TreeNode *ancestor;
    for (int i = 0; i < path_p.size() && i < path_q.size(); ++i) {
        if (path_p[i] == path_q[i]) {
            ancestor = path_p[i];
        } else {
            break;
        }
    }
    return ancestor;
}

TreeNode *lowestCommonAncestor3(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *ancestor = root;
    while (true) {
        if (p->val < ancestor->val && q->val < ancestor->val) {
            ancestor = ancestor->left;
        } else if (p->val > ancestor->val && q->val > ancestor->val) {
            ancestor = ancestor->right;
        } else {
            break;
        }
    }
    return ancestor;
}

#endif //ALGORITHM_LOWESTCOMMONANCESTOR_H
