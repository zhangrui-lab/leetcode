//
// Created by 张锐 on 2021/1/28.
//

#ifndef ALGORITHM_POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H
#define ALGORITHM_POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H

/*
 * 116. 填充每个节点的下一个右侧节点指针
 *  给定一个完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。
 *  填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 *  初始状态下，所有 next 指针都被设置为 NULL。
 *  你只能使用常量级额外空间。
 *  使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 *
 * 1. 层序遍历该二叉树，并设置每层的next链接
 * 2. 递归调用: 设置 left.next->rigth;
 *
 */

#include "../common.h"
#include <queue>

Node *populatingNextRightPointersInEachNode1(Node *root) {
    if (!root)
        return root;
    std::queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        int size = queue.size();
        Node *prev = nullptr, *curr = nullptr;
        while (size--) {
            curr = queue.front();
            queue.pop();
            // 设置链接
            if (prev)
                prev->next = curr;
            prev = curr;
            // 获取下一层
            if (curr->left)
                queue.push(curr->left);
            if (curr->right)
                queue.push(curr->right);
        }
    }
    return root;
}

Node *populatingNextRightPointersInEachNode2(Node *root) {
    if (!root)
        return root;
    Node *leftmost = root;
    while (leftmost->left) {
        Node *head = leftmost;
        while (head) {
            head->left->next = head->right;
            if (head->next) {
                head->right->next = head->next->left;
            }
            head = head->next;
        }
        leftmost = leftmost->left;
    }
    return root;
}


#endif //ALGORITHM_POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H
