//
// Created by Administrator on 2021/7/20.
//

#ifndef ALGORITHM_REARRANGETHELIST_H
#define ALGORITHM_REARRANGETHELIST_H

/**
 * 143. 重排链表
 *  给定一个单链表 L 的头节点 head ，单链表 L 表示为： L0 → L1 → … → Ln-1 → Ln  请将其重新排列后变为： L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
 *  不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 * 示例 1:
 *  输入: head = [1,2,3,4]
 *  输出: [1,4,2,3]
 * 示例 2:
 *  输入: head = [1,2,3,4,5]
 *  输出: [1,5,2,4,3]
 *
 * 解决思路:
 *  1. 利用stack后进先出的特性解决: 先将链表入栈, 指针p遍历链表, 当p指向元素和栈顶元素不同且栈顶元素不是p的后继时, 将p放入新链表, 若p和栈顶元素不同, 栈顶元素放入新链表.
 *  2. 线性表: 利用线性表存储该链表，然后利用线性表可以下标访问的特点，直接按顺序访问指定元素，重建该链表即可。
 *  3. 找链表中点 + 链表逆序 + 合并链表:  目标链表即为将原链表的左半端和反转后的右半端合并后的结果。
 *      a. 找到原链表的中点（们可以使用快慢指针来 O(N)O(N) 地找到链表的中间节点）。
 *      b. 将原链表的右半端反转（我们可以使用迭代法实现链表的反转）。
 *      c. 将原链表的两端合并。
 *
 * 双指针反转链表算法: prev(前驱指针), curr(当前迭代指针), next(算法执行过程中用于保留当前迭代指针的后继指针)
 *      next = curr->next;
 *      curr->next = prev;
 *      prev = curr;
 *      curr = next;
 * 反转示例: x->y->z->m->null;
 *      prev | curr | next | list
 *      -----------------------------
 *      null |  x  |   y  |  x->y->z->m->null
 *       x   |  y  |   z  |  x->null, y->z->m->null
 *       y   |  z  |   m  |  y->x->null, z->m->null
 *       z   |  m  | null |  z->y->x->null, m->null
 *       m   | null| null |  m->z->y->x->null, null
 */

#include "../common.h"
#include <stack>
#include <vector>

using namespace std;

void reorderList(ListNode *head) {
    ListNode *node;
    stack<ListNode *> nodes;
    for (node = head; node; node = node->next)
        nodes.push(node);
    for (node = head; node && node != nodes.top();) {
        nodes.top()->next = node->next == nodes.top() ? nullptr : node->next;
        node->next = nodes.top();
        node = nodes.top()->next;
        nodes.pop();
    }
    if (node == nodes.top()) {
        node->next = nullptr;
    }
}

void reorderList2(ListNode *head) {
    vector<ListNode *> nodes;
    for (ListNode *node = head; node; node = node->next)
        nodes.push_back(node);
    for (int i = 0, j = nodes.size() - 1; i <= j; ++i, --j) {
        if (i == j) {
            nodes[i]->next = nullptr;
        } else {
            nodes[j]->next = nodes[i]->next == nodes[j] ? nullptr : nodes[i]->next;
            nodes[i]->next = nodes[j];
        }
    }
}

void reorderList3(ListNode *head) {
    auto middleNode = [](ListNode *node) {
        ListNode *fast, *slow;
        for (fast = node, slow = node; fast->next && fast->next->next; fast = fast->next->next, slow = slow->next);
        return slow;
    };
    auto reverseList = [](ListNode *node) {
        ListNode *prev = nullptr, *next = nullptr, *curr = node;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    };
    auto mergeList = [](ListNode *l1, ListNode *l2) {
        ListNode *node = l1;
        for (ListNode *next1 = nullptr, *next2 = nullptr; node; node = next1, l2 = next2) {
            next1 = node->next;
            node->next = l2;
            next2 = l2 ? l2->next : nullptr;
            if (l2) l2->next = next1;
        }
    };
    ListNode *mid = middleNode(head), *l1 = head, *l2 = reverseList(mid->next);
    mid->next = nullptr;
    mergeList(l1, l2);
}

#endif //ALGORITHM_REARRANGETHELIST_H