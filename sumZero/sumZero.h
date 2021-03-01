//
// Created by 张锐 on 2021/3/1.
//

#ifndef ALGORITHM_SUMZERO_H
#define ALGORITHM_SUMZERO_H

/*
 * 1304. 和为零的N个唯一整数
 *  给你一个整数 n，请你返回任意一个由 n 个各不相同的整数组成的数组，并且这 n 个数相加和为 0 。
 */

#include <vector>
#include <random>

std::vector<int> sumZero(int n) {
    std::vector<int> nums(n);
    if (n % 2)
        nums[0] = 0;
    for (int i = n % 2; i + 1 < n; i += 2) {
        nums[i] = i+1;
        nums[i + 1] = -nums[i];
    }
    return nums;
}

#endif //ALGORITHM_SUMZERO_H
