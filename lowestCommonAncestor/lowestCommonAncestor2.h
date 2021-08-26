//
// Created by Administrator on 2021/8/26.
//

#ifndef ALGORITHM_LOWESTCOMMONANCESTOR2_H
#define ALGORITHM_LOWESTCOMMONANCESTOR2_H

/**
 * 236. 二叉树的最近公共祖先
 *  给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 *  百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 *
 * 求解策略:
 *  1. 遍历树, 获取到p,q的路径信息, 并获取其最近公共祖先. 参考235解法1
 *  2. dfs:
 *      遇到第一个结点时进行标记
 *          若在其子树中遇到第二个节点, 则第一个结点为最近公共祖先
 *          若在其子树中不存在第二个节点, 则回溯到其父节点中尝试寻找第二个子节点, 若找到, 则父节点为最近公共祖先.
 *  3. 用哈希表存储所有节点的父节点，然后我们就可以利用节点的父节点信息从 p 结点开始不断往上跳，并记录已经访问过的节点，再从 q 节点开始不断往上跳，如果碰到已经访问过的节点，那么这个节点就是我们要找的最近公共祖先。 (同1)
 */

#include "../common.h"
#include <vector>
#include <unordered_map>

using namespace std;

TreeNode *lowestCommonAncestor(TreeNode *parent, TreeNode *root, TreeNode *p, TreeNode *q, int &findNum) {
    static TreeNode *node = nullptr;
    if (root == p || root == q) {
        findNum++;
        node = findNum == 2 ? node : root;
    }
    if (!root || findNum == 2) return node;
    lowestCommonAncestor(root, root->left, p, q, findNum);
    lowestCommonAncestor(root, root->right, p, q, findNum);
    if (root == node && findNum == 1) node = parent;
    return node;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    int findNum = 0;
    return lowestCommonAncestor(nullptr, root, p, q, findNum);
}


bool dfs(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&ans) {
    if (root == nullptr) return false;
    bool lson = dfs(root->left, p, q, ans);
    bool rson = dfs(root->right, p, q, ans);
    if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
        ans = root;
    }
    return lson || rson || (root->val == p->val || root->val == q->val);
}

TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *ans;
    dfs(root, p, q, ans);
    return ans;
}


void dfs(TreeNode *root, unordered_map<int, TreeNode *> &fa, unordered_map<int, bool> &vis) {
    if (root->left != nullptr) {
        fa[root->left->val] = root;
        dfs(root->left, fa, vis);
    }
    if (root->right != nullptr) {
        fa[root->right->val] = root;
        dfs(root->right, fa, vis);
    }
}

TreeNode *lowestCommonAncestor3(TreeNode *root, TreeNode *p, TreeNode *q) {
    unordered_map<int, TreeNode *> fa;
    unordered_map<int, bool> vis;
    fa[root->val] = nullptr;
    dfs(root, fa, vis);
    while (p != nullptr) {
        vis[p->val] = true;
        p = fa[p->val];
    }
    while (q != nullptr) {
        if (vis[q->val]) return q;
        q = fa[q->val];
    }
    return nullptr;
}

#endif //ALGORITHM_LOWESTCOMMONANCESTOR2_H
