//
// Created by Administrator on 2021/8/26.
//

#ifndef ALGORITHM_ISVALIDSERIALIZATION_H
#define ALGORITHM_ISVALIDSERIALIZATION_H

/**
 * 331. 验证二叉树的前序序列化
 *  序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。
 */

#include <stack>
#include <string>
#include "../common.h"

using namespace std;

bool isValidSerialization(string preorder) {
    int n = preorder.length();
    int i = 0;
    stack<int> stk;
    stk.push(1);
    while (i < n) {
        if (stk.empty()) {
            return false;
        }
        if (preorder[i] == ',') {
            i++;
        } else if (preorder[i] == '#') {
            stk.top() -= 1;
            if (stk.top() == 0) {
                stk.pop();
            }
            i++;
        } else {
            // 读一个数字
            while (i < n && preorder[i] != ',') {
                i++;
            }
            stk.top() -= 1;
            if (stk.top() == 0) {
                stk.pop();
            }
            stk.push(2);
        }
    }
    return stk.empty() || stk.top() == 0;
}

bool isValidSerialization2(string preorder) {
    int n = preorder.length();
    int i = 0;
    int slots = 1;
    while (i < n) {
        if (slots == 0) {
            return false;
        }
        if (preorder[i] == ',') {
            i++;
        } else if (preorder[i] == '#') {
            slots--;
            i++;
        } else {
            // 读一个数字
            while (i < n && preorder[i] != ',') {
                i++;
            }
            slots++; // slots = slots - 1 + 2
        }
    }
    return slots == 0;
}

#endif //ALGORITHM_ISVALIDSERIALIZATION_H
