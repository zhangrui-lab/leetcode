//
// Created by 张锐 on 2021/1/15.
//

#ifndef ALGORITHM_SEARCHFORARANGE_H
#define ALGORITHM_SEARCHFORARANGE_H

/*
 * 在排序数组中查找元素的第一个和最后一个位置
 *  给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 
 * 
 * 在有序序列中寻找小于x的最后位置p1(最后一个小于target的元素)
 *  1 2 3 3 3 4 5
 *   |
 *   p1 (nums[p1] < target, nums[p1+1] >= target); p1 分割 < target 和 >= target的子序列
 * 
 * 在有序序列中寻找大于x的最前位置p2(第一个大于target的元素)
 *  1 2 3 3 3 4 5
 *           |
 *           p2 (nums[p2] > target, nums[p2-1] <= target); p2 分割 <= target 和 > target的子序列
 *
 *
 * 原问题等价于寻找 p1,p1.
 *  1. nums[p1+1] == target: 则target存在于序列中，返回 {p1+1, p2-1}
 *  2. nums[p1+1] != target: 则target存不在于序列中，返回 {-1， -1}
 */

#include <vector>

std::vector<int> searchForARange(std::vector<int> &nums, int target) {
    int lo = 0, hi = nums.size(), mid, p1, p2;
    // todo 此处寻找p1和以上描述策略不同
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    p1 = hi;
    // 寻找p2
    lo = 0, hi = nums.size();
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (nums[mid] <= target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    p2 = lo;
    return p1 < p2 ? std::vector({p1, p2 - 1}) : std::vector({-1, -1});
}

#endif //ALGORITHM_SEARCHFORARANGE_H
