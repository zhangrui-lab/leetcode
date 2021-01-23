//
// Created by 47302 on 2021/1/23.
//

#ifndef ALGORITHM_REVERSELINKEDLIST2_H
#define ALGORITHM_REVERSELINKEDLIST2_H

/*
 * 92. 反转链表 II
 *  反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 *  说明: 1 ≤ m ≤ n ≤ 链表长度。
 *
 * 1. stack辅助结构完成/递归实现
 * 2. 迭代实现
 */

#include "../common.h"
#include <stack>

ListNode *reverseLinkedList2(ListNode *head, int m, int n) {
    std::stack<ListNode *> stk;
    int cur = 1;
    ListNode *header = new ListNode, *tail = header, *prev = nullptr, *succ = nullptr;
    for (ListNode *node = head; node; cur++) {
        if (cur == m - 1)
            prev = node;
        if (cur == m)
            tail = node;
        if (cur == n + 1)
            succ = node;
        if (m <= cur && cur <= n) {
            ListNode *tmp = node->next;
            node->next = header->next;
            header->next = node;
            node = tmp;
        } else {
            node = node->next;
        }
    }
    tail->next = succ;
    (prev ? prev->next : head) = header->next;
    return head;
}

#endif //ALGORITHM_REVERSELINKEDLIST2_H
