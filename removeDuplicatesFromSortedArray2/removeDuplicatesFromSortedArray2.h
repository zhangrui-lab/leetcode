//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_REMOVEDUPLICATESFROMSORTEDARRAY2_H
#define ALGORITHM_REMOVEDUPLICATESFROMSORTEDARRAY2_H

/*
 * 80. 删除排序数组中的重复项 II
 *  给定一个增序排列数组 nums ，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
 *  不要使用额外的数组空间，你必须在原地 修改输入数组并在使用 O(1) 额外空间的条件下完成。
 *  说明：
 *      为什么返回数值是整数，但输出的答案是数组呢？
 *      请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 *
 */

#include <vector>

int removeDuplicatesFromSortedArray2(std::vector<int> &nums) {
    if (nums.empty())
        return 0;
    int i = 0, size = 0, curr = nums[i];
    for (int j = 0; j < nums.size(); ++j) {
        if (curr == nums[j]) {
            if (++size <= 2) {
                std::swap(nums[i++], nums[j]);
            }
        } else {
            size = 1;
            curr = nums[j];
            std::swap(nums[i++], nums[j]);
        }
    }
    return i;
}

#endif //ALGORITHM_REMOVEDUPLICATESFROMSORTEDARRAY2_H
