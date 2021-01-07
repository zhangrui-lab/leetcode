//
// Created by 张锐 on 2021/1/7.
//

#ifndef ALGORITHMS_ADDTWONUMBERS_H
#define ALGORITHMS_ADDTWONUMBERS_H

#include <stack>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x, ListNode *n = nullptr) : val(x), next(n) {}
};

// 逆序
ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2) {
    ListNode *resu = nullptr;
    ListNode *p = resu;
    int adva = 0;
    while (l1 || l2 || adva) {
        int op1 = l1 ? l1->val : 0;
        int op2 = l2 ? l2->val : 0;
        int tsum = op1 + op2 + adva;
        printf("%d+%d+%d= %d\n", op1, op2, adva, tsum);
        adva = tsum > 9 ? 1 : 0;
        if (!resu) {
            p = resu = new ListNode(tsum % 10);
        } else {
            p = p->next = new ListNode(tsum % 10);
        }
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return resu;
}

// 正序两数相加
ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
    std::stack<int> sl1, sl2;
    ListNode *resu = nullptr;
    ListNode *p = resu;
    for (ListNode *node = l1; node; sl1.push(node->val), node = node->next);
    for (ListNode *node = l2; node; sl2.push(node->val), node = node->next);
    int adva = 0;
    while (!sl1.empty() || !sl2.empty() || adva) {
        int op1 = sl1.empty() ? 0 : sl1.top();
        int op2 = sl2.empty() ? 0 : sl2.top();
        int tsum = op1 + op2 + adva;
        printf("%d+%d+%d= %d\n", op1, op2, adva, tsum);
        adva = tsum > 9 ? 1 : 0;
        if (!resu) {
            p = resu = new ListNode(tsum % 10);
        } else {
            p = p->next = new ListNode(tsum % 10);
        }
        if (!sl1.empty())
            sl1.pop();
        if (!sl2.empty())
            sl2.pop();
    }
    return resu;
}

#endif //ALGORITHMS_ADDTWONUMBERS_H
