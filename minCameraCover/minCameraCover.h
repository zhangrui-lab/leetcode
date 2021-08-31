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

int traversal(TreeNode *cur, int &result) {

    // 空节点，该节点有覆盖
    if (cur == NULL) return 2;

    int left = traversal(cur->left, result);    // 左
    int right = traversal(cur->right, result);  // 右

    // 情况1
    // 左右节点都有覆盖
    if (left == 2 && right == 2) return 0;

    // 情况2
    // left == 0 && right == 0 左右节点无覆盖
    // left == 1 && right == 0 左节点有摄像头，右节点无覆盖
    // left == 0 && right == 1 左节点有无覆盖，右节点摄像头
    // left == 0 && right == 2 左节点无覆盖，右节点覆盖
    // left == 2 && right == 0 左节点覆盖，右节点无覆盖
    if (left == 0 || right == 0) {
        result++;
        return 1;
    }

    // 情况3
    // left == 1 && right == 2 左节点有摄像头，右节点有覆盖
    // left == 2 && right == 1 左节点有覆盖，右节点有摄像头
    // left == 1 && right == 1 左右节点都有摄像头
    // 其他情况前段代码均已覆盖
    if (left == 1 || right == 1) return 2;

    // 以上代码我没有使用else，主要是为了把各个分支条件展现出来，这样代码有助于读者理解
    // 这个 return -1 逻辑不会走到这里。
    return -1;
}

int minCameraCover2(TreeNode *root) {
    int result = 0;
    // 情况4
    if (traversal(root, result) == 0) { // root 无覆盖
        result++;
    }
    return result;
}


#endif //ALGORITHM_MINCAMERACOVER_H
