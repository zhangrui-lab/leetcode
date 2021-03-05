//
// Created by 张锐 on 2021/3/5.
//

#ifndef ALGORITHM_ISPALINDROMELIST_H
#define ALGORITHM_ISPALINDROMELIST_H

/*
 * 234. 回文链表
 *  请判断一个链表是否为回文链表。
 *
 * 1. stack
 * 2. 保存至数组中并使用双指针
 * 3. 基于递归的策略
 * 4. 反转后半部分链表并执行比较
 */

#include "../common.h"

#include <stack>

bool isPalindromeList(ListNode *head) {
    std::stack<ListNode *> stk;
    for (auto node = head; node; node = node->next)
        stk.push(node);
    while (!stk.empty() && head->val == stk.top()->val) {
        stk.pop();
        head = head->next;
    }
    return !head;
}

bool isPalindromeList1(ListNode *head) {
    std::vector<int> vec;
    for (auto node = head; node; node = node->next)
        vec.push_back(node->val);
    int i = 0, j = vec.size() - 1;
    for (; i < j && vec[i] == vec[j]; ++i, --j);
    return i >= j;
}

bool isPalindromeList2(ListNode *&prev, ListNode *node) {
    bool eq = true;
    if (node) {
        if (!isPalindromeList2(prev, node->next)) {
            return false;
        }
        eq = prev->val == node->val;
        prev = prev->next;
    }
    return eq;
}

bool isPalindromeList2(ListNode *head) {
    return isPalindromeList2(head, head);
}

bool isPalindromeList3(ListNode *head) {
    auto endOfFirstHalf = [head](ListNode *node) {
        ListNode *fast = head, *slow = head;
        for (; fast->next && fast->next->next; fast = fast->next->next, slow = slow->next);
        return slow;
    };
    auto reverseList = [](ListNode *node) {
        ListNode *prev = nullptr;
        ListNode *curr = node;
        while (curr) {
            ListNode *t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        return prev;
    };
    if (!head)
        return true;
    // 找到前半部分链表的尾节点并反转后半部分链表
    ListNode *firstHalfEnd = endOfFirstHalf(head);
    ListNode *secondHalfStart = reverseList(firstHalfEnd->next);
    ListNode *p1 = head, *p2 = secondHalfStart;
    bool ans = true;
    while (ans && p2 != nullptr) {
        ans = p1->val == p2->val;
        p1 = p1->next;
        p2 = p2->next;
    }
    firstHalfEnd->next = reverseList(secondHalfStart);
    return ans;
}


#endif //ALGORITHM_ISPALINDROMELIST_H
