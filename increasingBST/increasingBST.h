//
// Created by 张锐 on 2021/3/11.
//

#ifndef ALGORITHM_INCREASINGBST_H
#define ALGORITHM_INCREASINGBST_H

/*
 * 897. 递增顺序查找树
 *  给你一个树，请你按中序遍历重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。
 */
//输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]
//
//      5
//     / \
//    3   6
//   / \   \
//  2   4   8
// /       / \
//1       7   9
//                               |r:null,t:4| return 4;
//                               |r:4,t:5|    h=4; 4->left=null; 4->right=5; return 4;(4->5)
/*                               |r:null,t:3|                                                                                                                                                 |r:null,t:9|  |t:null,t:null|; return 9;
 * |r:null,t:1| return 1;        |r:null,t:2|                                                                                                                                                       |r:9,t:null|
 * |r:1,t:2| h=1; 1->left=null;  1->right=2; return 1;(1->2)                                                                                                        |r:null,t:7| return 7;          |r:null,t:8| return 8;
 * |r:2,t:3| h=1; 2->left=null;  2->right=3; return 1;(1->2->3)                                                                                                     |r:7,t:8|    h=7; 7->left=null; 7->right=8; return 7;(7->8)
 * |r:3,t:5| h=1; 3->left=null;  3->right=4; return 1;(1->2->3->4->5)                                   |r:null,t:6| return 6;                                      |r:8,t:null| h=7; 8->left=null; 8->right=9; return 7; (7->8->9)
 * |r:5,t:null| h=1; 5->left=null; 5->right=6;                                                          |r:6,t:null| h=6; h->left=null; h->right=7; return 6;(6->7->8->9)
 * =========
 * 1->2->3->4->5->6->7->8->9
 */
//输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
//            \
//             7
//              \
//               8
//                \
//                 9

#include "../common.h"

TreeNode *increasingBST(TreeNode *root, TreeNode *tail = nullptr) {
    if (!root) return tail;
    auto head = increasingBST(root->left, root);
    root->left = nullptr;
    root->right = increasingBST(root->right, tail);
    return head;
}

#endif //ALGORITHM_INCREASINGBST_H
