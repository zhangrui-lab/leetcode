//
// Created by 张锐 on 2021/1/19.
//

#ifndef ALGORITHM_ROTATERIGHT_H
#define ALGORITHM_ROTATERIGHT_H

/*
 * 61. 旋转链表
 *  给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 *
 * 旋转之后的头节点为: n-k%n, 新的尾节点为 n-k%n-1
 *  0->1->2->NULL, k = 4, n = 3.
 *  2->0->1->NULL
 */

#include "../common.h"

ListNode *rotateRight(ListNode *head, int k) {
    if (!head) {
        return head;
    }
    int len = 0;
    ListNode *last;
    for (ListNode *node = head; node; node = node->next) {
        last = node;
        len++;
    }
    last->next = head;
    int h = len - k % len, t = len - k % len - 1;
    ListNode *nh = nullptr;
    ListNode *nt = nullptr;
    int i = 0;
    for (ListNode *node = head; node; node = node->next, i++) {
        if (i == h)
            nh = node;
        if (i == t)
            nt = node;
        if (nh && nt)
            break;
    }
    nt->next = nullptr;
    return nh;
}

#endif //ALGORITHM_ROTATERIGHT_H
