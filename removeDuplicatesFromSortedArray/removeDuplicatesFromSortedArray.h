//
// Created by 张锐 on 2021/1/13.
//

#ifndef ALGORITHM_REMOVEDUPLICATESFROMSORTEDARRAY_H
#define ALGORITHM_REMOVEDUPLICATESFROMSORTEDARRAY_H

/*
 * 删除排序数组中的重复项
 *
 * 双指针法：跳过重复的项
 */

#include <vector>

int removeDuplicates(std::vector<int> &nums) {
    if (nums.empty())
        return 0;
    int j = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[j]) {
            //printf("swap(%d(%d), %d(%d))\n", i, nums[i], j, nums[j]);
            nums[++j] = nums[i];
        }
    }
    return j + 1;
}

#endif //ALGORITHM_REMOVEDUPLICATESFROMSORTEDARRAY_H
