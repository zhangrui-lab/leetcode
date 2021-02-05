//
// Created by 张锐 on 2021/2/5.
//

#ifndef ALGORITHM_copyRandomList1_H
#define ALGORITHM_copyRandomList1_H

/*
 * 138. 复制带随机指针的链表
 *  给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 *  要求返回这个链表的 深拷贝。
 *  我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
 *  val：一个表示 Node.val 的整数。
 *  random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 *
 * 1. DFS
 * 2. BFS
 */

#include "../common.h"
#include <queue>
#include <unordered_map>

RNode *copyRandomList1(RNode *node, std::unordered_map<RNode *, RNode *> &copied) {
    if (!node)
        return node;
    if (copied.count(node))
        return copied[node];
    RNode *newNode = new RNode(node->val);
    copied[node] = newNode;
    newNode->next = copyRandomList1(node->next, copied);
    newNode->random = copyRandomList1(node->random, copied);
    return newNode;
}

RNode *copyRandomList1(RNode *head) {
    std::unordered_map<RNode *, RNode *> copied;
    return copyRandomList1(head, copied);
}

RNode *copyRandomList2(RNode *head) {
    if (!head)
        return head;
    std::queue<RNode *> queue;
    std::unordered_map<RNode *, RNode *> copied;
    queue.push(head);
    copied[head] = new RNode(head->val);
    while (!queue.empty()) {
        RNode *node = queue.front();
        queue.pop();
        RNode *next = node->next, *random = node->random;
        if (next && !copied.count(next)) {
            copied[next] = new RNode(next->val);
            queue.push(next);
        }
        if (random && !copied.count(random)) {
            copied[random] = new RNode(random->val);
            queue.push(random);
        }
        copied[node]->next = next ? copied[next] : nullptr;
        copied[node]->random = random ? copied[random] : nullptr;
    }
    return copied[head];
}

#endif //ALGORITHM_copyRandomList1_H
