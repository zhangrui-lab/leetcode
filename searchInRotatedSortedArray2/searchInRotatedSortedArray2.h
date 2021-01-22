//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_SEARCHINROTATEDSORTEDARRAY2_H
#define ALGORITHM_SEARCHINROTATEDSORTEDARRAY2_H

/*
 * 81. 搜索旋转排序数组 II
 *  假设按照升序排序的数组在预先未知的某个点上进行了旋转。 ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
 *  编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
 *  本题中的 nums 可能包含重复元素
 *
 * 二分查找策略进行搜索
 */

#include <vector>

//bool searchInRotatedSortedArray2(std::vector<int> &nums, int target) {
//    int lo = 0, hi = nums.size(), mid;
//    while (lo < hi) {
//        if (nums[mid] == target)
//            return true;
////        if (nums[lo] < nums[mid])
//    }
//}

bool searchInRotatedSortedArray2(std::vector<int> &nums, int target) {
    if (nums.empty())
        return false;
    if (nums.size() == 1)
        return nums[0] == target ? true : false;
    int lo = 0, hi = nums.size(), mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (nums[mid] == target)
            return true;
        if (nums[lo] < nums[mid]) {
            if (nums[lo] <= target && target < nums[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        } else if (nums[lo] > nums[mid]) {
            if (nums[mid] < target && target <= nums[hi - 1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        } else {
            lo++;
        }
    }
    return false;
}


#endif //ALGORITHM_SEARCHINROTATEDSORTEDARRAY2_H
