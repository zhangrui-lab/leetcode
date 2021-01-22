//
// Created by 张锐 on 2021/1/15.
//

#ifndef ALGORITHM_SEARCHINROTATEDSORTEDARRAY_H
#define ALGORITHM_SEARCHINROTATEDSORTEDARRAY_H

/*
 * 搜索旋转排序数组
 *  升序排列的整数数组 nums 在预先未知的某个点上进行了旋转（例如， [0,1,2,4,5,6,7] 经旋转后可能变为 [4,5,6,7,0,1,2] ）。
 *  请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 *
 * 4,5,6,7,0,1,2
 *  序列肯定不是升序排列，但序列必定由两个升序排列子序列拼接而成。
 *  前置序列的最小值必定大于后置序列的最大值。
 *
 *  lo              mid               hi
 *  |----------------|----------------|
 *  nums[lo] <= nums[mid]: 则 lo ~ mid 升序排列。
 *  nums[lo] > nums[mid]: 则旋转点位于 lo~mid中，且 mid ~ hi 升序排列。
 *
 *
 *  A. 0 ～ mid 升序：
 *  target存在两种情况
 *      1. nums[0] <= target <= nums[mid]; (0~mid)
 *      2. target > nums[mid] || target < nums[0]; (mid ~ nums.size-1)
 *      /|
 *     / |
 *    /| |
 *   / | |
 *  /  | |
 *     | |    /
 *   mid |   /
 *       |  /
 *       | /
 *       |/
 *
 *  B.  0 ～ mid 存在转折：
 *  target存在两种情况
 *      1. nums[mid] <= target <= nums[nums.size-1]; (mid ~ nums.size-1)
 *      2. target > nums[nums.size-1] || target < nums[mid]; (0 ~ mid)
 *
 *        mid
 *    /    |
 *   /     |
 *  /      |
 *         |    /
 *         |   /
 *         |  /
 *         | /
 *         |/
 *         /
 *        /
 */

#include <vector>

int searchInRotatedSortedArray(std::vector<int> &nums, int target) {
    if (nums.empty())
        return -1;
    if (nums.size() == 1)
        return nums[0] == target ? 0 : -1;
    int lo = 0, hi = nums.size(), mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (nums[mid] == target)
            return mid;
        if (nums[lo] <= nums[mid]) {                                // 情况A
            if (nums[lo] <= target && target < nums[mid]) {         // A1
                hi = mid;
            } else {                                                // A2
                lo = mid + 1;
            }
        } else {                                                    // 情况B
            if (nums[mid] < target && target <= nums[hi - 1]) {     // B1
                lo = mid + 1;
            } else {                                                // B2
                hi = mid;
            }
        }
    }
    return -1;
}

#endif //ALGORITHM_SEARCHINROTATEDSORTEDARRAY_H
