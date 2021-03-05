
//
// Created by 张锐 on 2021/3/5.
//

#ifndef ALGORITHM_MOVEZEROES_H
#define ALGORITHM_MOVEZEROES_H

/*
 * 283. 移动零
 *  给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 1. 模拟冒泡排序
 * 2. 双指针
 *  [0,1,0,3,12]
 *  指针i界定值为0的区间的左边界，指针j子左向右迭代。i=j时，未迭代到0元素。
 *  i!=j时，[i,j) 区间为0元素，nums[j]=0时，j++, nums[j]!=0时，std::swap(nums[i++], nums[j++]);
 */

#include <vector>

void moveZeroes(std::vector<int> &nums) {
    auto bubb = [&](int hi) {
        bool over = true;
        for (int i = 1; i < hi; ++i) {
            if (nums[i - 1] == 0) {
                std::swap(nums[i - 1], nums[i]);
                over = false;
            }
        }
        return over;
    };
    for (int i = nums.size(), over = false; i >= 0 && !over; --i) {
        over = bubb(i);
    }
}

void moveZeroes1(std::vector<int> &nums) {
    for (int i = 0, j = 0, n = nums.size(); j < n; ++j)
        if (nums[j] != 0)
            std::swap(nums[i++], nums[j]);
}

#endif //ALGORITHM_MOVEZEROES_H
