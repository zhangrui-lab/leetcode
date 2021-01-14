//
// Created by 张锐 on 2021/1/14.
//

#ifndef ALGORITHM_NEXTPERMUTATION_H
#define ALGORITHM_NEXTPERMUTATION_H

/*
 * 下一个排列
 * 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 *
 *
 * 1. 给定输入序列， 如何才能使其值更小：较小值占据权重较高位。则最小值必定顺序排列，最大值必定逆序排列。
 * 2. 如何获取给定序列的较大值，使该序列其他组合的值不介于两者之间
 *  从低位开始寻找和计数，在0~i位中找到大于i位的最大值 j, 将j放置在i位，并将0~i位顺序排列。
 *  寻找j: 从低位到高位寻找到第一个逆序对(i,m)。从m回溯找到大于i的最后者。
 *
 * 优化：并将0~i位顺序排列
 *  i为从后到钱的第一个逆序对。故0 ~ i必定为倒序，将其进行反转即可
 */

#include <vector>

void nextPermutation(std::vector<int> &nums) {
    if (nums.size() < 2)
        return;
    int i, j = -1;
    for (i = nums.size() - 1; i > 0; --i) {
        if (nums[i - 1] < nums[i]) {
            j = i - 1;
            while (i + 1 < nums.size() && nums[i + 1] > nums[j]) i++;
            break;
        }
    }
    if (j == -1) {
        std::sort(nums.begin(), nums.end());
    } else {
        std::swap(nums[i], nums[j]);
        std::sort(nums.begin()+j+1, nums.end());
    }
}

void nextPermutation2(std::vector<int> &nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i >= 0) {
        int j = nums.size() - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            j--;
        }
        std::swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}


#endif //ALGORITHM_NEXTPERMUTATION_H
