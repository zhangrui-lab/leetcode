//
// Created by 张锐 on 2021/3/12.
//

#ifndef ALGORITHM_CUSTOMSTACK_H
#define ALGORITHM_CUSTOMSTACK_H

/*
 * 1381. 设计一个支持增量操作的栈
 *
 * 请你设计一个支持下述操作的栈。
 *  实现自定义栈类 CustomStack ：
 *  CustomStack(int maxSize)：用 maxSize 初始化对象，maxSize 是栈中最多能容纳的元素数量，栈在增长到 maxSize 之后则不支持 push 操作。
 *  void push(int x)：如果栈还未增长到 maxSize ，就将 x 添加到栈顶。
 *  int pop()：弹出栈顶元素，并返回栈顶的值，或栈为空时返回 -1 。
 *  void inc(int k, int val)：栈底的 k 个元素的值都增加 val 。如果栈中元素总数小于 k ，则栈中的所有元素都增加 val 。
 *
 * 1. 常规实现
 * 2. increment函数优化
 *  设置一个与capacity等大的数组保存元素的增量，使整体的操作复杂度变为O(1);
 */

#include <vector>

class CustomStack {
public:
    CustomStack(int maxSize) : size(0), capacity(maxSize), elements(new int[capacity]) {
    }

    void push(int x) {
        if (size >= capacity)
            return;
        elements[size++] = x;
    }

    int pop() {
        return size > 0 ? elements[--size] : -1;
    }

    void increment(int k, int val) {
        for (int i = 0, n = std::min(k, size); i < n; ++i)
            elements[i] += val;
    }

    ~CustomStack() {
        delete[] elements;
    }

private:
    int size;
    int capacity;
    int *elements;
};

class CustomStackOptimize {
public:
    std::vector<int> stk, add;
    int top;

    CustomStackOptimize(int maxSize) {
        stk.resize(maxSize);
        add.resize(maxSize);
        top = -1;
    }

    void push(int x) {
        if (top != stk.size() - 1) {
            ++top;
            stk[top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            return -1;
        }
        int ret = stk[top] + add[top];
        if (top != 0) {
            add[top - 1] += add[top];
        }
        add[top] = 0;
        --top;
        return ret;
    }

    void increment(int k, int val) {
        int lim = std::min(k - 1, top);
        if (lim >= 0) {
            add[lim] += val;
        }
    }
};


#endif //ALGORITHM_CUSTOMSTACK_H
