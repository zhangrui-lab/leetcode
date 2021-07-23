//
// Created by Administrator on 2021/7/23.
//

#ifndef ALGORITHM_MINVALUEINROTATIONSORTARRAY_H
#define ALGORITHM_MINVALUEINROTATIONSORTARRAY_H

/**
 * 154. 寻找旋转排序数组中的最小值 II
 *  已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
 *  若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
 *  若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
 *  注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
 *  给你一个可能存在重复元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的最小元素 。
 *
 * 解决策略:
 *  1. 蛮力遍历
 *  2. 二分查找
 */

#include <vector>

using namespace std;

int minValueInRotationSortArray(vector<int> &nums) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        int pivot = low + (high - low) / 2;
        if (nums[pivot] < nums[high]) {
            high = pivot;
        } else if (nums[pivot] > nums[high]) {
            low = pivot + 1;
        } else {
            high -= 1;
        }
    }
    return nums[low];
}

#endif //ALGORITHM_MINVALUEINROTATIONSORTARRAY_H
