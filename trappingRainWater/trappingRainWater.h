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
 * 指针left从左往右，right从右往左。lMax指向当前左侧最高柱子，rMax指向当前右侧最高柱子。
 *  lMax,rMax均初始化为第一个逆序的柱子。
 *  当left找到大于lMax的柱子时，更新lMax, 更新oldLMax～lMax之间可容的水量。
 *  当right找到大于rMax的柱子时，更新rMax, 更新oldRMax～rMax之间可容的水量。
 * height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 0,1,0,2,1,0,1,3,2,1,2,1
 *   |   |       |     |
 * lMax  |       |    rMax
 *       |       |
 *      lMax    rMax
 *
 *
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


#endif //ALGORITHM_TRAPPINGRAINWATER_H
