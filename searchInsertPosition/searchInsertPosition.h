//
// Created by 张锐 on 2021/1/15.
//

#ifndef ALGORITHM_SEARCHINSERTPOSITION_H
#define ALGORITHM_SEARCHINSERTPOSITION_H

#include <vector>
#include <cassert>

/*
 * 搜索插入位置
 *  给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。你可以假设数组中无重复元素。
 */

int searchInsert(std::vector<int> &nums, int target) {
    int lo = 0, hi = nums.size(), mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        nums[mid] <= target ? (lo=mid+1) : (hi = mid);
    }
    return lo - 1 >= 0 && nums[lo - 1] == target ? lo - 1 : lo;
}

#endif //ALGORITHM_SEARCHINSERTPOSITION_H
