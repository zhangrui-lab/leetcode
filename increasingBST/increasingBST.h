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
//       5
//      / \
//    3    6
//   / \    \
//  2   4    8
// /        / \
//1        7   9
//
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
