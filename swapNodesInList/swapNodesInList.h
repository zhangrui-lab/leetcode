//
// Created by 47302 on 2021/1/12.
//

#ifndef ALGORITHM_SWAPNODESINLIST_H
#define ALGORITHM_SWAPNODESINLIST_H

/*
 * 两两交换链表中的节点
 */

#include "../common.h"

ListNode *swapPairs(ListNode *head) {
    ListNode *first = new ListNode(0, head);
    ListNode *p1 = first;
    ListNode *p2;
    while (p1->next != NULL && p1->next->next != NULL) {
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = p2->next->next;
        p1->next->next = p2;
        p1 = p2;
    }
    return first->next;
}

#endif //ALGORITHM_SWAPNODESINLIST_H
