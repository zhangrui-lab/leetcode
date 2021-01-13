//
// Created by 张锐 on 2021/1/13.
//

#ifndef ALGORITHM_REVERSEKGROUP_H
#define ALGORITHM_REVERSEKGROUP_H

/*
 * K 个一组翻转链表:
 *  给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 *
 * 利用堆栈进行翻转
 *  链表入堆栈，达到翻转条件时依次出堆栈。链表遍历结束时，尝试进行最后的翻转并更新当前未节点的后继节点（防止循环和不足k的遗漏）
 *
 * 更换翻转策略
 *  计算长度，判断是否可以翻转。对长度等于k的子序列执行尾插入并拼接。
 */

#include "../common.h"
#include <stack>
#include <utility>

ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *header = new ListNode(0, head);
    ListNode *curr = header;
    std::stack<ListNode *> waitReverse;
    auto reverse = [&]() {
        if (waitReverse.size() != k) return;
        while (!waitReverse.empty()) {
            curr->next = waitReverse.top();
            curr = curr->next;
            waitReverse.pop();
        }
    };
    int step = 0;
    for (ListNode *node = head; node; node = node->next, step++) {
        reverse();
        waitReverse.push(node);
    }
    reverse();
    while (waitReverse.size() > 1) {
        waitReverse.pop();
    }
    curr->next = waitReverse.empty() ? nullptr : waitReverse.top();
    return header->next;
}

// 翻转一个子链表，并且返回新的头与尾
std::pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *tail) {
    ListNode *prev = tail->next;
    ListNode *p = head;
    while (prev != tail) {
        ListNode *nex = p->next;
        p->next = prev;
        prev = p;
        p = nex;
    }
    return {tail, head};
}

ListNode *reverseKGroup1(ListNode *head, int k) {
    ListNode *hair = new ListNode(0, head);
    ListNode *pre = hair;

    while (head) {
        ListNode *tail = pre;
        // 查看剩余部分长度是否大于等于 k
        for (int i = 0; i < k; ++i) {
            tail = tail->next;
            if (!tail) {
                return hair->next;
            }
        }
        ListNode *nex = tail->next;
        auto result = myReverse(head, tail);
        head = result.first;
        tail = result.second;
        // 把子链表重新接回原链表
        pre->next = head;
        tail->next = nex;
        pre = tail;
        head = tail->next;
    }
    return hair->next;
}


#endif //ALGORITHM_REVERSEKGROUP_H
