//
// Created by Administrator on 2021/7/21.
//

#ifndef ALGORITHM_INSERTIONSORTLIST_H
#define ALGORITHM_INSERTIONSORTLIST_H

/**
 * 147. 对链表进行插入排序
 *  从第一个元素开始，该链表可以被认为已经部分排序。每次迭代时，从输入数据中移除一个元素，并原地将其插入到已排好序的链表中。
 *
 * 插入排序算法：
 *  插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
 *  每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
 *  重复直到所有输入数据插入完为止。
 *
 * 示例 1：
 *  输入: 4->2->1->3
 *  输出: 1->2->3->4
 *
 * 示例 2：
 *  输入: -1->5->3->4->0
 *  输出: -1->0->3->4->5
 */

#include "../common.h"

ListNode *insertionSortList(ListNode *head) {
    if (!head)
        return head;
    ListNode *header = new ListNode(0, head);
    for (ListNode *prev = head, *posNode = nullptr; prev && prev->next;) {
        for (posNode = header; posNode != prev; posNode = posNode->next) {
            if (prev->next->val < posNode->next->val) {
                ListNode *curr = prev->next;
                prev->next = curr->next;
                curr->next = posNode->next;
                posNode->next = curr;
                break;
            }
        }
        if (posNode == prev) {
            prev = prev->next;
        }
    }
    return header->next;
}

#endif //ALGORITHM_INSERTIONSORTLIST_H
