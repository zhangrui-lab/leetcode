//
// Created by 47302 on 2021/1/11.
//

#ifndef ALGORITHM_CONTAINERWITHMOSTWATER_H
#define ALGORITHM_CONTAINERWITHMOSTWATER_H

/*
 * 盛最多水的容器
 *
 * 双指针法，不断试探可能出现的最大容量值
 *
 */

#include <vector>

int maxArea(std::vector<int> &height) {
    int area = 0;
    std::size_t lo = 0, hi = height.size() - 1;
    while (lo < hi) {
        int tmp = std::min(height[lo], height[hi]) * (hi - lo);
        area = std::max(area, tmp);
        printf("[%d,%d]=%d\n", lo, hi, tmp);
        height[lo] <= height[hi] ? (++lo) : (--hi);
    }
    return area;
}

#endif //ALGORITHM_CONTAINERWITHMOSTWATER_H
