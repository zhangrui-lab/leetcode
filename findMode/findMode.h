//
// Created by Administrator on 2021/8/27.
//

#ifndef ALGORITHM_FINDMODE_H
#define ALGORITHM_FINDMODE_H

/**
 * 501. 二叉搜索树中的众数
 *  给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 *  假定 BST 有如下定义：
 *      结点左子树中所含结点的值小于等于当前结点的值
 *      结点右子树中所含结点的值大于等于当前结点的值
 *      左子树和右子树都是二叉搜索树
 *
 * 求解策略:
 *  1. map
 *  2. 中序遍历
 *  3. Morris 中序遍历:
 *      我们在中序遍历的时候，一定先遍历左子树，然后遍历当前节点，最后遍历右子树。在常规方法中，我们用递归回溯或者是栈来保证遍历完左子树可以再回到当前节点，但这需要我们付出额外的空间代价。
 *      我们需要用一种巧妙地方法可以在 O(1) 的空间下，遍历完左子树可以再回到当前节点。我们希望当前的节点在遍历完当前节点的前驱之后被遍历，我们可以考虑修改它的前驱节点的 right 指针。
 *      当前节点的前驱节点的 right 指针可能本来就指向当前节点（前驱是当前节点的父节点），也可能是当前节点左子树最右下的节点。如果是后者，我们希望遍历完这个前驱节点之后再回到当前节点，可以将它的 right 指针指向当前节点。
 *      Morris 中序遍历的一个重要步骤就是寻找当前节点的前驱节点，并且 Morris 中序遍历寻找下一个点始终是通过转移到 right 指针指向的位置来完成的。
 *          如果当前节点没有左子树，则遍历这个点，然后跳转到当前节点的右子树。
 *          如果当前节点有左子树，那么它的前驱节点一定在左子树上，我们可以在左子树上一直向右行走，找到当前点的前驱节点。
 *          如果前驱节点没有右子树，就将前驱节点的 right 指针指向当前节点。这一步是为了在遍历完前驱节点后能找到前驱节点的后继，也就是当前节点。
 *          如果前驱节点的右子树为当前节点，说明前驱节点已经被遍历过并被修改了 right 指针，这个时候我们重新将前驱的右孩子设置为空，遍历当前的点，然后跳转到当前节点的右子树。
 */

#include <vector>
#include <unordered_map>
#include "../common.h"

using namespace std;

void findMode(TreeNode *root, unordered_map<int, int> &count) {
    if (!root) return;;
    count[root->val]++;
    findMode(root->left, count);
    findMode(root->right, count);
}

vector<int> findMode(TreeNode *root) {
    int max = INT_MIN;
    vector<int> ans;
    unordered_map<int, int> count;
    findMode(root, count);
    for (auto iter = count.cbegin(); iter != count.cend(); iter++) {
        if (max < iter->second) {
            max = iter->second;
            ans.assign({iter->first});
        } else if (max == iter->second) {
            ans.push_back(iter->first);
        }
    }
    return ans;
}


vector<int> answer;
int base, count, maxCount;

void update(int x) {
    if (x == base) {
        ++count;
    } else {
        count = 1;
        base = x;
    }
    if (count == maxCount) {
        answer.push_back(base);
    }
    if (count > maxCount) {
        maxCount = count;
        answer = vector<int>{base};
    }
}

void dfs(TreeNode *o) {
    if (!o) {
        return;
    }
    dfs(o->left);
    update(o->val);
    dfs(o->right);
}

vector<int> findMode2(TreeNode *root) {
    dfs(root);
    return answer;
}

vector<int> findMode3(TreeNode *root) {
    TreeNode *cur = root, *pre = nullptr;
    while (cur) {
        if (!cur->left) {
            update(cur->val);
            cur = cur->right;
            continue;
        }
        pre = cur->left;
        while (pre->right && pre->right != cur) {
            pre = pre->right;
        }
        if (!pre->right) {
            pre->right = cur;
            cur = cur->left;
        } else {
            pre->right = nullptr;
            update(cur->val);
            cur = cur->right;
        }
    }
    return answer;
}

#endif //ALGORITHM_FINDMODE_H
