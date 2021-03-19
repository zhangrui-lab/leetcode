//
// Created by 张锐 on 2021/3/19.
//

#ifndef ALGORITHM_MAXWIDTHRAMP_H
#define ALGORITHM_MAXWIDTHRAMP_H

/*
 * 962. 最大宽度坡
 *  给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。
 *  找出 A 中的坡的最大宽度，如果不存在，返回 0 。
 * eg:
 *  输入：[6,0,8,2,1,5]
 *  输出：4
 * 解释：
 *  最大宽度的坡为 (i, j) = (1, 5): A[1] = 0 且 A[5] = 5.
 *
 * 1. 蛮力策略
 *  寻找每一个位置作为坡的左端点时的坡的最大宽度。并返回其最大值。
 *
 * 2. 排序
 *  对元素位置依据元素值进行排序得到序列 X。 A[X[i]] > A[X[i-1]];  故只需要遍历 X， 获取差值最大者。
 *
 * 3. 基于单调递栈
 *  单调栈其实就是栈内元素以单调递增或单调递减进行存放，单调栈求解由两个部分组成，一个是初始化单调栈的过程，一个是利用单调栈计算的过程。
 *  1. 初始化单调栈: 初始化过程即从序列中找到一个单调递减的子序列，比如在[6,0,8,2,1,5]中从初始位置开始的单调递减序列就是[6,0]（不连续是可以的），单调栈中把序号记录下来即[0,1]。
 *  2. 单调栈计算: 计算过程很简单，从后往前遍历，当元素比栈顶序号的元素大（或等于）时，就计算栈顶的序号（并弹出）和位置i的差值，因为我们要找到最大的两者之差（即宽度）。
 */

#include <vector>
#include <stack>

int maxWidthRamp(std::vector<int> &A) {
    auto maxWidth = [](std::vector<int> &A, int left) {
        int max = 0;
        for (int i = left + 1, n = A.size(); i < n; i++)
            if (A[left] <= A[i])
                max = i - left;
        return max;
    };
    int max = 0;
    for (int i = 0, n = A.size(); i < n; ++i)
        max = std::max(max, maxWidth(A, i));
    return max;
}

int maxWidthRamp2(std::vector<int> &A) {
    int n = A.size(), min = n, width = 0;
    std::vector<int> pos(n);
    for (int i = 0; i < n; ++i)
        pos[i] = i;
    std::sort(pos.begin(), pos.end(), [&A](int n1, int n2) {
        return A[n1] < A[n2] ? true : (A[n1] > A[n2] ? false : n1 < n2);
    });
    for (auto p : pos) {
        width = std::max(p - min, width);
        min = std::min(p, min);
    }
    return width;
}

int maxWidthRamp3(std::vector<int> &A) {
    int ans = 0;
    std::stack<int> stk;
    for (int i = 0, n = A.size(); i < n; i++)
        if (i == 0 || A[stk.top()] >= A[i])
            stk.push(i);
    for (int i = A.size() - 1; i > ans; i--)
        while (!stk.empty() && A[stk.top()] <= A[i]) {
            ans = std::max(ans, i - stk.top());
            stk.pop();
        }
    return ans;
}

#endif //ALGORITHM_MAXWIDTHRAMP_H
