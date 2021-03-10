//
// Created by 张锐 on 2021/3/10.
//

#ifndef ALGORITHM_REVERSEPRINT_H
#define ALGORITHM_REVERSEPRINT_H

/*
 * 剑指 Offer 06. 从尾到头打印链表
 *  输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 * eg:
 *  输入：head = [1,3,2]
 *  输出：[2,3,1]
 *
 * 1. 递归回溯
 * 2. stack
 */

#include "../common.h"
#include <vector>
#include <stack>

void reversePrint(ListNode *head, std::vector<int> &ans) {
    if (!head)
        return;
    reversePrint(head->next, ans);
    ans.push_back(head->val);
}

std::vector<int> reversePrint(ListNode *head) {
    std::vector<int> ans;
    reversePrint(head, ans);
    return ans;
}

std::vector<int> reversePrint1(ListNode *head) {
    std::vector<int> ans;
    std::stack<ListNode *> stk;
    for (auto node = head; node; node = node->next) stk.push(node);
    while (!stk.empty()) {
        ans.push_back(stk.top()->val);
        stk.pop();
    }
    return ans;
}

#endif //ALGORITHM_REVERSEPRINT_H
