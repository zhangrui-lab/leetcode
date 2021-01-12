//
// Created by 47302 on 2021/1/12.
//

#ifndef ALGORITHM_MERGEKLISTS_H
#define ALGORITHM_MERGEKLISTS_H

/*
 * 合并K个升序链表
 *
 * 分而治之：将问题分解问可以处理的基本情况(一个列表or两个列表的归并)在合并。
 */

#include "../common.h"
#include <vector>

ListNode *merge2List(ListNode *l1, ListNode *l2) {
    ListNode *header = new ListNode;
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

ListNode *mergeKLists(std::vector<ListNode *> &lists, int lo, int hi) {
    if (hi - lo == 1)
        return lists[lo];
    int mid = (lo + hi) >> 1;
    ListNode* l = mergeKLists(lists, lo, mid);
    ListNode* r = mergeKLists(lists, mid, hi);
    return merge2List(l, r);
}

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    if (lists.empty())
        return nullptr;
    return mergeKLists(lists, 0, lists.size());
}
#endif //ALGORITHM_MERGEKLISTS_H
