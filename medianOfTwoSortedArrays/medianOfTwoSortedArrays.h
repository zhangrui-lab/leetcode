//
// Created by 张锐 on 2021/1/7.
//

#ifndef ALGORITHMS_MEDIANOFTWOSORTEDARRAYS_H
#define ALGORITHMS_MEDIANOFTWOSORTEDARRAYS_H

//4. 寻找两个正序数组的中位数
//给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

#include <vector>

//蛮力求解：归并
double findMedianSortedArrays1(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::vector<int> nums;
    int l1 = nums1.size(), l2 = nums2.size(), l = l1 + l2;
    nums1.push_back(INT_MAX);
    nums2.push_back(INT_MAX);
    for (int i = 0, p = 0, q = 0; i < l; ++i) {
        nums.push_back(nums1[p] <= nums2[q] ? nums1[p++] : nums2[q++]);
    }
    return (nums[l >> 1] + nums[(l - 1) >> 1]) / 2.0;
}

int getKthElement(const std::vector<int> &nums1, const std::vector<int> &nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    int index1 = 0, index2 = 0;

    while (true) {
        // 边界情况
        if (index1 == m) {
            return nums2[index2 + k - 1];
        }
        if (index2 == n) {
            return nums1[index1 + k - 1];
        }
        if (k == 1) {
            return std::min(nums1[index1], nums2[index2]);
        }

        // 正常情况
        int newIndex1 = std::min(index1 + k / 2 - 1, m - 1);
        int newIndex2 = std::min(index2 + k / 2 - 1, n - 1);
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];
        if (pivot1 <= pivot2) {
            k -= newIndex1 - index1 + 1;
            index1 = newIndex1 + 1;
        } else {
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
}

// 基于二分查找的策略
double findMedianSortedArrays2(std::vector<int> &nums1, std::vector<int> &nums2) {
    int totalLength = nums1.size() + nums2.size();
    if (totalLength % 2 == 1) {
        return getKthElement(nums1, nums2, (totalLength + 1) / 2);
    } else {
        return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
    }
}


#endif //ALGORITHMS_MEDIANOFTWOSORTEDARRAYS_H

