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
 * 2. 递归    // todo
 * 3. 双指针
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

ListNode *reverseList1(ListNode *prev, ListNode *curr) {

}

ListNode *reverseList1(ListNode *head) {

}


#endif //ALGORITHM_REVERSELIST_H
