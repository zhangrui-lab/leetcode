//
// Created by 张锐 on 2021/1/12.
//

#ifndef ALGORITHM_COMMON_H
#define ALGORITHM_COMMON_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *n = nullptr) : val(x), next(n) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *left = nullptr, TreeNode *right = nullptr) : val(x), left(left), right(right) {}
};

#endif //ALGORITHM_COMMON_H
