//
// Created by 张锐 on 2021/3/10.
//

#ifndef ALGORITHM_REVERSELIST_H
#define ALGORITHM_REVERSELIST_H

/*
 * 剑指 Offer 24. 反转链表
 *  定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
 *
 * 1. stack
 * 2. 递归
 * 3. 迭代
 */

#include "../common.h"
#include <stack>

ListNode *reverseList(ListNode *head) {
    if (!head)
        return nullptr;
    std::stack<ListNode *> stk;
    for (ListNode *node = head; node; node = node->next)
        stk.push(node);
    ListNode *node = nullptr;
    while (!stk.empty()) {
        if (!node) {
            head = node = stk.top();
        } else {
            node = node->next = stk.top();
            node->next = nullptr;
        }
        stk.pop();
    }
    return head;
}

ListNode *reverseList1(ListNode *head, ListNode *&newHead) {
    if (!head)
        return nullptr;
    auto next = reverseList1(head->next, newHead);
    if (next)
        next->next = head;
    else
        newHead = head;
    head->next = nullptr;
    return head;
}

ListNode *reverseList1(ListNode *head) {
    ListNode *newHead = nullptr;
    reverseList1(head, newHead);
    return newHead;
}

ListNode *reverseList2(ListNode *head) {
    if (!head || !head->next)
        return head;
    ListNode *header = new ListNode(), *prev = head, *curr = head->next, *tail = head->next->next;
    while (curr) {
        header->next = curr;
        curr->next = prev;
        prev = curr;
        curr = tail;
        tail = tail ? tail->next : tail;
    }
    head->next = nullptr;
    return header->next;
}

ListNode *reverseList3(ListNode *head) {
    ListNode *prev = nullptr, *curr = head, *tmp;
    while (curr) {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return
}


#endif //ALGORITHM_REVERSELIST_H
