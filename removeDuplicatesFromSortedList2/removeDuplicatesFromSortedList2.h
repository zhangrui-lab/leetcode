//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_REMOVEDUPLICATESFROMSORTEDLIST2_H
#define ALGORITHM_REMOVEDUPLICATESFROMSORTEDLIST2_H

/*
 * 82. 删除排序链表中的重复元素 II
 *  给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中没有重复出现的数字。
 */

#include "../common.h"

ListNode *removeDuplicatesFromSortedList22(ListNode *head) {
    ListNode *header = new ListNode, *prev = header;
    for (ListNode *node = head; node;) {
        ListNode *succ = node->next;
        while (succ && succ->val == node->val) succ = succ->next;
        if (node->next == succ)
            prev = prev->next = node;
        node = succ;
    }
    prev->next = nullptr;
    return header->next;
}

#endif //ALGORITHM_REMOVEDUPLICATESFROMSORTEDLIST2_H
