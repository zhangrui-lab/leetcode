//
// Created by 张锐 on 2021/1/12.
//

#ifndef ALGORITHM_MERGETWOSORTEDLISTS_H
#define ALGORITHM_MERGETWOSORTEDLISTS_H

/*
 * 合并两个有序链表
 *
 * 可以利用虚拟的头哨兵节点提升代码的可读性
 */

#include "../common.h"

ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
    ListNode *merged = nullptr;
    ListNode *node = merged;
    while (l1 || l2) {
        ListNode *tmp = l1 ? (l2 ? (l1->val <= l2->val ? l1 : l2) : l1) : l2;
        if (!merged) {
            merged = node = tmp;
        } else {
            node->next = tmp;
            node = node->next;
        }
        tmp == l1 ? (l1 = l1->next) : (l2 = l2->next);
    }
    return merged;
}

ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2) {
    ListNode *header = new ListNode();
    ListNode *prev = header;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    prev->next = l1 ? l1 : l2;
    return header->next;
}

#endif //ALGORITHM_MERGETWOSORTEDLISTS_H
