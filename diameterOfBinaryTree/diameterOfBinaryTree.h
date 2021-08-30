//
// Created by Administrator on 2021/8/30.
//

#ifndef ALGORITHM_DIAMETEROFBINARYTREE_H
#define ALGORITHM_DIAMETEROFBINARYTREE_H

/**
 * 543. 二叉树的直径
 *  给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 */

#include "../common.h"

using namespace std;

int depth(TreeNode *rt, int &ans) {
    if (rt == NULL) {
        return 0; // 访问到空节点了，返回0
    }
    int L = depth(rt->left, ans); // 左儿子为根的子树的深度
    int R = depth(rt->right, ans); // 右儿子为根的子树的深度
    ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
    return max(L, R) + 1; // 返回该节点为根的子树的深度
}

int diameterOfBinaryTree(TreeNode *root) {
    ans = 1;
    depth(root, ans);
    return ans - 1;
}

#endif //ALGORITHM_DIAMETEROFBINARYTREE_H
