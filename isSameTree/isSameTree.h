//
// Created by 47302 on 2021/1/26.
//

#ifndef ALGORITHM_ISSAMETREE_H
#define ALGORITHM_ISSAMETREE_H

/*
 * 100. 相同的树
 *  给定两个二叉树，编写一个函数来检验它们是否相同。如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的
 */

#include "../common.h"

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr || q == nullptr)
        return p == q;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

#endif //ALGORITHM_ISSAMETREE_H
