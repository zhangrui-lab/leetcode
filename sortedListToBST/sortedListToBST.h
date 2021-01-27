//
// Created by 张锐 on 2021/1/27.
//

#ifndef ALGORITHM_SORTEDLISTTOBST_H
#define ALGORITHM_SORTEDLISTTOBST_H

/*
 * 109. 有序链表转换二叉搜索树
 *  给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 *  本题中，一个高度平衡二叉树是指一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1。
 *
 * 1. 分治: 计算链表长度，获取中位数作为根节点并拆分链表。
 * 2. 分治: 双指针法计获取中位数作为根节点并拆分链表。
 * 3. 分治: 先构建左子树避免链表中位数的定位。
 */

#include "../common.h"

TreeNode *sortedListToBST1(ListNode *head) {
    int size = 0;
    for (ListNode *tmp = head; tmp; tmp = tmp->next, ++size);
    if (size == 0)
        return nullptr;
    if (size == 1)
        return new TreeNode(head->val, nullptr, nullptr);
    ListNode *mid = head, *prev = nullptr;
    for (int i = 0; i < size >> 1; ++i) {
        prev = mid;
        mid = mid->next;
    }
    // 断开链接
    if (prev)
        prev->next = nullptr;
    // 构造节点
    TreeNode *root = new TreeNode(mid->val);
    root->left = sortedListToBST1(head);
    root->right = sortedListToBST1(mid->next);
    return root;
}

ListNode *getMedian(ListNode *left, ListNode *right) {
    ListNode *fast = left;
    ListNode *slow = left;
    while (fast != right && fast->next != right) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

TreeNode *sortedListToBST2(ListNode *left, ListNode *right) {
    if (left == right)
        return nullptr;
    ListNode *median = getMedian(left, right);
    TreeNode *root = new TreeNode(
            median->val,
            sortedListToBST2(left, median),
            sortedListToBST2(median->next, right)
    );
    return root;
}

TreeNode *sortedListToBST2(ListNode *head) {
    return sortedListToBST2(head, nullptr);
}

TreeNode *sortedListToBST3(ListNode *&head, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int mid = (left + right + 1) / 2;
    TreeNode *root = new TreeNode();
    root->left = sortedListToBST3(head, left, mid - 1);
    root->val = head->val;
    head = head->next;
    root->right = sortedListToBST3(head, mid + 1, right);
    return root;
}

TreeNode *sortedListToBST3(ListNode *head) {
    int length = 0;
    for (ListNode *tmp = head; tmp; ++length, tmp = tmp->next);
    return sortedListToBST3(head, 0, length - 1);
}


#endif //ALGORITHM_SORTEDLISTTOBST_H
