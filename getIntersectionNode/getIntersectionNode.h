//
// Created by 张锐 on 2021/3/18.
//

#ifndef ALGORITHM_GETINTERSECTIONNODE_H
#define ALGORITHM_GETINTERSECTIONNODE_H

/*
 * 面试题 02.07. 链表相交
 *  给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
 * eg:
 *  输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 *  输出：Reference of the node with value = 8
 *  输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 *
 * 1. set/map...
 * 2. 对headA中的每个节点，判断其是否在headB中
 * 3. 因为如果链表A和链表B相交于D的话,那么说明D结点即在A上又在B上,而D之后的元素自然也就均在A和B上了,因为他们是通过next指针相连的.
 *  如果有相交的结点D的话,每条链的头结点先走完自己的链表长度,然后回头走另外的一条链表,那么两结点一定为相交于D点,因为这时每个头结点走的距离是一样的,
 *  都是 AD + BD + DC,而他们每次又都是前进1,所以距离相同,速度又相同,固然一定会在相同的时间走到相同的结点上,即D点
 */

#include "../common.h"
#include <unordered_set>

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    std::unordered_set<ListNode *> counting;
    for (auto node = headA; node; node = node->next) counting.insert(node);
    for (auto node = headB; node; node = node->next)
        if (counting.count(node))
            return node;
    return nullptr;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    for (auto nodeA = headA; nodeA; nodeA = nodeA->next)
        for (auto nodeB = headB; nodeB; nodeB = nodeB->next)
            if (nodeA == nodeB)
                return nodeA;
    return nullptr;
}

ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;
    while (a != b) {
        a = a != nullptr ? a->next : headB;
        b = b != nullptr ? b->next : headA;
    }
    return a;
}

#endif //ALGORITHM_GETINTERSECTIONNODE_H
