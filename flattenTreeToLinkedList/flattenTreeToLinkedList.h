//
// Created by 张锐 on 2021/1/27.
//

#ifndef ALGORITHM_FLATTENTREETOLINKEDLIST_H
#define ALGORITHM_FLATTENTREETOLINKEDLIST_H

/*
 * 114. 二叉树展开为链表
 *  给你二叉树的根结点 root ，请你将它展开为一个单链表：
 *      展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
 *      展开后的单链表应该与二叉树先序遍历顺序相同。
 *
 * 1. 深度优先
 */

#include "../common.h"


void flattenTreeToLinkedList(TreeNode *root) {
    TreeNode *left = root->left, *right = root->right;

}

#endif //ALGORITHM_FLATTENTREETOLINKEDLIST_H
