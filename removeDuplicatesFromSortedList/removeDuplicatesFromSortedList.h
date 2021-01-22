//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_REMOVEDUPLICATESFROMSORTEDLIST_H
#define ALGORITHM_REMOVEDUPLICATESFROMSORTEDLIST_H

/*
 * 83. 删除排序链表中的重复元素
 *  给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 */

#include "../common.h"

ListNode *removeDuplicatesFromSortedList(ListNode *head) {
    ListNode* curr = head;
    while (curr && curr->next) {
        if (curr->val == curr->next->val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

ListNode *removeDuplicatesFromSortedList(ListNode *head) {
    if (!head)
        return head;
    ListNode *header = new ListNode(0, head), *prev = header;
    for (ListNode *node = head->next; node; node = node->next) {
        if (prev->next->val != node->val) {
            prev->next->next = node;
            prev = prev->next;
        }
    }
    prev->next->next = nullptr;
    return header->next;
}

#endif //ALGORITHM_REMOVEDUPLICATESFROMSORTEDLIST_H
