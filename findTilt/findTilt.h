//
// Created by 张锐 on 2021/3/15.
//

#ifndef ALGORITHM_FINDTILT_H
#define ALGORITHM_FINDTILT_H

/*
 * 563. 二叉树的坡度
 *  给定一个二叉树，计算整个树的坡度 。
 *  一个树的节点的坡度定义即为，该节点左子树的节点之和和右子树节点之和的差的绝对值 。如果没有左子树的话，左子树的节点之和为 0 ；没有右子树的话也是一样。空结点的坡度是 0 。
 *  整个树的坡度就是其所有节点的坡度之和。
 *
 * 1. 后续遍历
 */

#include <utility>
#include "../common.h"

std::pair<int, int> findTiltDFS(TreeNode *root) {
    if (!root)
        return {0, 0};
    auto lt = findTiltDFS(root->left);
    auto rt = findTiltDFS(root->right);
    return {lt.first + rt.first + root->val,
            lt.second + rt.second + std::abs(lt.first - rt.first)};    // 可使用全局变量保存坡度,只返回当前节点的子树节点之和
}

int findTilt(TreeNode *root) {
    return findTiltDFS(root).second;
}

#endif //ALGORITHM_FINDTILT_H
