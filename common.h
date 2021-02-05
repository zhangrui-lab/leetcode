//
// Created by 张锐 on 2021/1/12.
//

#ifndef ALGORITHM_COMMON_H
#define ALGORITHM_COMMON_H

#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x = 0, ListNode *n = nullptr) : val(x), next(n) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x = 0, TreeNode *left = nullptr, TreeNode *right = nullptr) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int _val = 0, Node *_left = nullptr, Node *_right = nullptr, Node *_next = nullptr)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class GNode {
public:
    int val;
    std::vector<GNode *> neighbors;

    GNode(int _val = 0, std::vector<GNode *> _neighbors = std::vector<GNode *>()) : val(_val), neighbors(_neighbors) {}
};

class RNode {
public:
    int val;
    RNode *next;
    RNode *random;

    RNode(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

#endif //ALGORITHM_COMMON_H
