//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_MERGESORTEDARRAY_H
#define ALGORITHM_MERGESORTEDARRAY_H

/*
 * 88. 合并两个有序数组
 *  给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 *  初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。
 *
 * 1. 额外的数组保存合并的结果
 * 2. 自后向前比较，不断将当前最大值就位
 */
#include <vector>

void mergeSortedArray1(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    std::vector<int> nums(n + m);
    for (int p = 0, i = 0, j = 0; p < n + m; ++p) {
        int op1 = i < m ? nums1[i] : INT_MAX;
        int op2 = j < n ? nums2[j] : INT_MAX;
        nums[p] = op1 <= op2 ? nums1[i++] : nums2[j++];
    }
    nums1 = nums;
}

void mergeSortedArray2(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int size = n + m;
    std::vector<int> nums(size);
    for (int i = m - 1, j = n - 1; size > 0; --size) {
        int op1 = i > -1 ? nums1[i] : INT_MIN;
        int op2 = j > -1 ? nums2[j] : INT_MIN;
        nums1[size - 1] = op1 > op2 ? nums1[i--] : nums2[j--];
    }
}

#endif //ALGORITHM_MERGESORTEDARRAY_H
