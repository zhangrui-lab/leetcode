//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_LARGESTRECTANGLEAREA_H
#define ALGORITHM_LARGESTRECTANGLEAREA_H

/*
 * 84. 柱状图中最大的矩形
 *  给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 * 矩形的面积 = 底(参与当前矩形面积计算的柱状图的长度) * 高(参与当前矩形面积计算的柱状图的最低高度)
 *
 * 1. 遍历柱状图，对与每一个可能的柱，获取其作为左边界时的面积。获取最小值；
 * 2. 遍历柱状图，对与每一个可能的柱，获取以当前柱的高度为矩形的面积。获取最小值；
 * 3. 单调栈优化方案2。
 */

#include <vector>
#include <stack>

int largestRectangleArea1(std::vector<int> &heights) {
    int largest = 0, n = heights.size();
    for (int i = 0; i < n; ++i) {
        int h = heights[i];
        for (int j = i; j < n; ++j) {
            h = std::min(h, heights[j]);
            largest = std::max(largest, (j - i + 1) * h);
        }
    }
    return largest;
}

int largestRectangleArea2(std::vector<int> &heights) {
    int largest = 0, n = heights.size();
    for (int i = 0; i < n; ++i) {
        int l = i, r = i;
        while (l >= 0 && heights[l] >= heights[i]) l--;
        while (r < n && heights[i] <= heights[r]) r++;
        largest = std::min((r - l - 1) * heights[i], largest);
    }
    return largest;
}

int largestRectangleArea3(std::vector<int> &heights) {
    std::stack<int> stk;
    int largest = 0, n = heights.size();
    for (int i = 0; i < n; ++i) {
        if (!stk.empty() && heights[stk.top()] > heights[i]) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int j = stk.top();
                stk.pop();
                int l = stk.empty() ? i : i - stk.top() - 1;
                largest = std::max(l * heights[j], largest);
            }
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        int j = stk.top();
        stk.pop();
        int l = stk.empty() ? n : n - stk.top() - 1;
        largest = std::max(l * heights[j], largest);
    }
    return largest;
}

int largestRectangleArea4(std::vector<int> &heights) {
    int n = heights.size();
    std::vector<int> left(n), right(n, n);
    std::stack<int> mono_stack;
    for (int i = 0; i < n; ++i) {
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
            right[mono_stack.top()] = i;
            mono_stack.pop();
        }
        left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
        mono_stack.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
}

#endif //ALGORITHM_LARGESTRECTANGLEAREA_H
