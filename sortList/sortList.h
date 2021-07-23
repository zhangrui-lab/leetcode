//
// Created by Administrator on 2021/7/23.
//

#ifndef ALGORITHM_SORTLIST_H
#define ALGORITHM_SORTLIST_H

/**
 * 148. 排序链表
 *  给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 *
 * 进阶：
 *  你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 *
 * 求解策略:
 *  1. 借助 vector, list 等数据结构和算法实现.
 *  2. 归并策略
 */

#include <vector>
#include "../common.h"

using namespace std;

ListNode *sortList(ListNode *head) {
    vector<int> vec;
    for (ListNode *node = head; node; node = node->next)
        vec.push_back(node->val);
    sort(vec.begin(), vec.end());
    ListNode *header = new ListNode(), *curr = header;
    for (int i = 0, l = vec.size(); i < l; ++i) {
        curr = (curr->next = new ListNode(vec[i]));
    }
    return header->next;
}

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return sortList(head, nullptr);
    }

    ListNode *sortList(ListNode *head, ListNode *tail) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};

#endif //ALGORITHM_SORTLIST_H
