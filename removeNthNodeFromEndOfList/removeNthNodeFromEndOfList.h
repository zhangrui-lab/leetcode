//
// Created by 张锐 on 2021/1/12.
//

#ifndef ALGORITHMS_REMOVENTHNODEFROMENDOFLIST_H
#define ALGORITHMS_REMOVENTHNODEFROMENDOFLIST_H

/*
 * 删除链表的倒数第N个节点
 *
 * 方法1: 计算链表长度和待删除元素的位置并执行删除。
 * 方法2: 利用堆栈执行遍历元素，并弹出第n+1个元素为待删除元素的直接前驱元素。
 * 方法3: 间隔为n的双指针。
 */

#include <cassert>
#include <stack>
#include "../common.h"


ListNode *removeNthFromEnd1(ListNode *head, int n) {
    int nodeNum = 0;
    for (ListNode *node = head; node; node = node->next, ++nodeNum);
    assert(nodeNum >= n);
    nodeNum -= n;
    ListNode *node = head;
    ListNode *prev = nullptr;
    while (nodeNum--) {
        prev = node;
        node = node->next;
    }
    (prev == nullptr ? head : prev->next) = node->next;

    delete node;
    return head;
}

ListNode *removeNthFromEnd2(ListNode *head, int n) {
    stack < ListNode * > nodes;
    for (ListNode *node = head; node; node = node->next) {
        nodes.push(node);
    }
    ListNode *node = head;
    ListNode *prev = nullptr;
    while (n--) {
        node = nodes.top();
        nodes.pop();
    }
    prev = nodes.empty() ? nullptr : nodes.top();
    (prev == nullptr ? head : prev->next) = node->next;
    delete node;
    return head;
}

ListNode *removeNthFromEnd3(ListNode *head, int n) {
    ListNode *prev = nullptr;
    ListNode *node = head;
    // node移动n位，此时prev指向待删除指针(head)的直接前驱节点(nullptr)
    for (int i = 0; i < n; ++i) {
        node = node->next;
    }
    for (; node; node = node->next) {
        prev = prev ? prev->next : head;
    }
    // 获取待删除节点
    node = prev ? prev->next : head;
    (prev == nullptr ? head : prev->next) = node->next;
    delete node;
    return head;
}

#endif //ALGORITHMS_REMOVENTHNODEFROMENDOFLIST_H
