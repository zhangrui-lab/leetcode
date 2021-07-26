//
// Created by Administrator on 2021/7/26.
//

#ifndef ALGORITHM_REMOVELISTELEMENTS_H
#define ALGORITHM_REMOVELISTELEMENTS_H

/**
 * 203. 移除链表元素
 *  给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回新的头节点 。
 *
 * 解决策略:
 *  1. 迭代策略: 判断节点值和val相等时移除. 遍历过程采用当前节点的直接前驱节点进行.
 *  2. 递归策略 
 */

#include "../common.h"

ListNode *removeElements(ListNode *head, int val) {
    ListNode *header = new ListNode(0, head);
    for (ListNode *node = header; node && node->next;) {
        if (node->next->val == val)
            node->next = node->next->next;
        else
            node = node->next;
    }
    return header->next;
}

ListNode *removeElements2(ListNode *head, int val) {
    if (head == nullptr) {
        return head;
    }
    head->next = removeElements2(head->next, val);
    return head->val == val ? head->next : head;
}

#endif //ALGORITHM_REMOVELISTELEMENTS_H
