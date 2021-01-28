//
// Created by 张锐 on 2021/1/28.
//

#ifndef ALGORITHM_POPULATINGNEXTRIGHTPOINTERSINEACHNODE2_H
#define ALGORITHM_POPULATINGNEXTRIGHTPOINTERSINEACHNODE2_H

/*
 * 117. 填充每个节点的下一个右侧节点指针 II
 *  填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 *  初始状态下，所有 next 指针都被设置为 NULL。
 *  进阶：
 *      你只能使用常量级额外空间。
 *      使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 *
 * 1. 基于queue实现的，层序遍历
 * 2. 使用已建立的 next 指针
 */

#include <queue>

Node *populatingNextRightPointersInEachNode21(Node *root) {
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


void populatingNextRightPointersInEachNode22(Node *&last, Node *&p, Node *&nextStart) {
    if (last) {
        last->next = p;
    }
    if (!nextStart) {
        nextStart = p;
    }
    last = p;
}

Node *populatingNextRightPointersInEachNode22(Node *root) {
    if (!root) {
        return nullptr;
    }
    Node *start = root;
    while (start) {
        Node *last = nullptr, *nextStart = nullptr;
        for (Node *p = start; p != nullptr; p = p->next) {
            if (p->left) {
                populatingNextRightPointersInEachNode22(last, p->left, nextStart);
            }
            if (p->right) {
                populatingNextRightPointersInEachNode22(last, p->right, nextStart);
            }
        }
        start = nextStart;
    }
    return root;
}


#endif //ALGORITHM_POPULATINGNEXTRIGHTPOINTERSINEACHNODE2_H
