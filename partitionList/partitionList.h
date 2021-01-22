//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_PARTITIONLIST_H
#define ALGORITHM_PARTITIONLIST_H

/*
 * 86. 分隔链表
 *  给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。你应当保留两个分区中每个节点的初始相对位置。
 *
 *  1. 两个链表，一个保存小于x的元素； 另一个保存大等于于x的元素。拼接两者即完成分割
 */

#include "../common.h"

ListNode *partitionList(ListNode *head, int x) {
    ListNode *l = new ListNode, *r = new ListNode, *lp = l, *rp = r;
    for (ListNode *node = head; node; node = node->next) {
        if (node->val < x)
            lp = lp->next = node;
        else
            rp = rp->next = node;
    }
    rp->next = nullptr;
    lp->next = r->next;
    return l->next;
}

#endif //ALGORITHM_PARTITIONLIST_H
