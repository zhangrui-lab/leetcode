//
// Created by Administrator on 2021/7/19.
//

#ifndef ALGORITHM_CIRCULARLINKEDLIST_H
#define ALGORITHM_CIRCULARLINKEDLIST_H

/**
 * 142. 环形链表 II
 *  给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 *  为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
 *  说明：不允许修改给定的链表。
 *
 * 解决思路:
 *  策略                                                                                        空间复杂度     时间复杂度
 *  1.遍历并保存访问过的链表节点.当某节点被重复访问时证明出现了环.第一次被重复访问的节点为开始入环的第一个节点.      O(n)         O(n)
 *  2.堆地址空间从低到高进行分配...(仅当链表节点顺序申请空间时)                                             O(1)         O(n)
 *  3.快慢指针:快指针移动速度为慢指针2倍, 当存在环时, 快慢指针必定在换中某位置相遇. 且满指针移动到环入口和         O(n)         O(n)
 *    起点移动到环入口处的距离相等.
 */

#include "../common.h"
#include <set>

using namespace std;

ListNode *circularLinkedList(ListNode *head) {
    set<const ListNode *> nodes;
    for (ListNode *node = head; node != nullptr; node = node->next) {
        if (nodes.count(node) != 0) {
            return node;
        }
        nodes.insert(node);
    }
    return nullptr;
}

ListNode *circularLinkedList2(ListNode *head) {
    for (ListNode *node = head; node; node = node->next) {
        if (node->next && node > node->next)
            return node;
    }
    return nullptr;
}

ListNode *circularLinkedList3(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
        slow = slow->next;
        if (fast->next == nullptr) {
            return nullptr;
        }
        fast = fast->next->next;
        if (fast == slow) {
            ListNode *ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;
}

#endif //ALGORITHM_CIRCULARLINKEDLIST_H
