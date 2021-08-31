//
// Created by Administrator on 2021/8/31.
//

#ifndef ALGORITHM_MINCAMERACOVER_H
#define ALGORITHM_MINCAMERACOVER_H

/**
 * 968. 监控二叉树
 *  给定一个二叉树，我们在树的节点上安装摄像头。节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。计算监控树的所有节点所需的最小摄像头数量。
 *
 * 求解策略:
 *  考虑监控以x为根的二叉树, 在节点x处是否放置摄像头:
 *      放置: 只需要覆盖x->left, x->right对应的两颗子树即可
 *      不放置: 则除了覆盖 root 的两棵子树之外，孩子 left,right 之一必须要安装摄像头，从而保证 root 会被监控到。
 *  状态:
 *      状态 a：root 必须放置摄像头的情况下，覆盖整棵树需要的摄像头数目。
 *      状态 b：覆盖整棵树需要的摄像头数目，无论 root 是否放置摄像头。
 *      状态 c：覆盖两棵子树需要的摄像头数目，无论节点 root 本身是否被监控到。
 *      a >= b >= c
 *  x(a,b,c), x.left(la,lb,lc), x.right(ra,rb,rc)
 *  a = lc+rc+1;
 *  b = min(a, min(la+rb, ra+lb));
 */

#include "../common.h"

using namespace std;

struct Status {
    int a, b, c;
};

Status dfs(TreeNode *root) {
    if (root == nullptr)
        return {INT_MAX / 2, 0, 0};
    auto[la, lb, lc] = dfs(root->left);
    auto[ra, rb, rc]= dfs(root->right);
    int a = lc + rc + 1, b = min(a, min(la + rb, lb + ra)), c = min(a, lb + rb);
    return {a, b, c};
}

int minCameraCover(TreeNode *root) {
    return dfs(root).b;
}

#endif //ALGORITHM_MINCAMERACOVER_H
