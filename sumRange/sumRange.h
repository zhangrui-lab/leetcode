//
// Created by 张锐 on 2021/3/1.
//

#ifndef ALGORITHM_SUMRANGE_H
#define ALGORITHM_SUMRANGE_H

/*
 * 303. 区域和检索 - 数组不可变
 *  给定一个整数数组  nums，求出数组从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点。
 *
 * 前缀和:
 *  psum[i]=sum( nums[-1, i) );
 *  sumRange(i,j) = psum[j] - psum[i] + nums[j];
 */

#include <vector>

int sumRange(std::vector<int> &nums, int i, int j) {
    int sum = 0;
    for (int k = 0; k < nums.size(); ++k) {
        if (i <= k && k <= j)
            sum += nums[k];
    }
    return sum;
}

int sumRange1(std::vector<int> &nums, int i, int j) {
    std::vector<int> psum(nums.size(), 0);
    for (int k = 1; k < nums.size(); ++k)
        psum[k] = psum[k - 1] + nums[k - 1];
    return psum[j] - psum[i] + nums[j];
}

#endif //ALGORITHM_SUMRANGE_H
