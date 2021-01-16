//
// Created by 张锐 on 2021/1/15.
//

#ifndef ALGORITHM_TRAPPINGRAINWATER_H
#define ALGORITHM_TRAPPINGRAINWATER_H

/*
 * 接雨水
 *  给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 * 蛮力策略
 *  直接按问题描述进行。对于数组中的每个元素，我们找出下雨后水能达到的最高位置，等于两边最大高度的较小值减去当前高度的值。
 *
 * 双指针法：
 *  情况1: 当发现的lMax<=rMax时，left~right中的雨水容量由当前位置高度和lMax决定。我们移动left指针，直至新发现的lMax>rMax.
 *  情况2: 当发现的lMax>rMax时，left~right中的雨水容量由当前位置高度和rMax决定。我们移动right指针，直至新发现的rMax>lMax.
 * height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 0,1,0,2,1,0,1,3,2,1,2,1
 *   |   |       |     |
 * lMax  |       |    rMax
 *       |       |
 *      lMax    rMax
 *
 * stack
 *  使用stack界定当前stack顶元素的左右边界。
 */


#include <vector>


int trappingRainWater1(std::vector<int> &height) {
    int container = 0;
    for (int i = 0; i < height.size(); ++i) {
        int lMax = 0, rMax = 0;
        for (int j = i - 1; j >= 0; --j) {
            lMax = height[j] > lMax ? height[j] : lMax;
        }
        for (int j = i + 1; j < height.size(); ++j) {
            rMax = height[j] > rMax ? height[j] : rMax;
        }
        container += std::max(std::min(lMax, rMax) - height[i], 0);
    }
    return container;
}

int trappingRainWater2(std::vector<int> &height) {
    if (height.empty())
        return 0;
    int container = 0, n = height.size();
    std::vector<int> lMax(n), rMax(n);
    lMax[0] = height[0];
    for (int i = 1; i < n; ++i)
        lMax[i] = std::max(height[i], lMax[i - 1]);
    rMax[n - 1] = height[n - 1];
    for (int j = n - 2; j >= 0; --j)
        rMax[j] = std::max(height[j], rMax[j + 1]);
    for (int k = 0; k < n; ++k) {
        container += std::min(lMax[k], rMax[k]) - height[k];
    }
    return container;
}

int trappingRainWater3(std::vector<int> &height) {
    int container = 0;
    std::stack<int> stk;
    for (int i = 0; i < height.size(); ++i) {
        while (!stk.empty() && height[i] >= height[stk.top()]) {
            int top = stk.top();
            stk.pop();
            if (stk.empty()) {
                break;
            }
            int diff = std::min(height[i], height[stk.top()]) - height[top];
            int distance = i - stk.top() - 1;
            container += diff * distance;
        }
        stk.push(i);
    }
    return container;
}

// 双指针策略
int trappingRainWater4(std::vector<int> &height) {
    if (height.empty())
        return 0;
    int container = 0, left = 1, right = height.size() - 2;
    int lMax = height[0], rMax = height[height.size() - 1];
    while (left <= right) {
        while (left <= right && lMax <= rMax) {
            if (height[left] >= lMax)
                lMax = height[left];
            else
                container += lMax - height[left];
            //printf("lMax:%d, rMax:%d, left:%d, +%d=%d\n", lMax, rMax, left, lMax - height[left], container);
            left++;
        }
        while (left <= right && lMax > rMax) {
            if (height[right] >= rMax)
                rMax = height[right];
            else
                container += rMax - height[right];
            //printf("lMax:%d, rMax:%d, right:%d, +%d=%d\n", lMax, rMax, right, rMax - height[right], container);
            right--;
        }
    }
    return container;
}

int trappingRainWater5(std::vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        } else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}

#endif //ALGORITHM_TRAPPINGRAINWATER_H
