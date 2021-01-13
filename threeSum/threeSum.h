//
// Created by 47302 on 2021/1/11.
//

#ifndef ALGORITHM_THREESUM_H
#define ALGORITHM_THREESUM_H

/*
 * 三数之和
 *
 * 蛮力策略
 * 考察所有可能的三位数之和，取出其中和为0的不重复的三元组。(使用排序策略排除重复元素)
 *
 * 优化
 * 第三层循环和第二层循环进行合并
 */

#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> sz;
    for (int i = 0; i < nums.size(); ++i) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;
            for (int k = j + 1; k < nums.size(); ++k) {
                if (k != j + 1 && nums[k] == nums[k - 1]) continue;
                if (nums[i] + nums[j] + nums[k] == 0) {
                    sz.push_back({i, j, k});
                }
            }
        }
    }
    return sz;
}

std::vector<std::vector<int>> threeSum1(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> sz;
    for (int i = 0; i < nums.size(); ++i) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        int k = nums.size() - 1;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;
            while (j < k && nums[i] + nums[j] + nums[k] > 0) k--;
            if (j == k)
                break;
            if (nums[i] + nums[j] + nums[k] == 0) {
                sz.push_back({nums[i], nums[j], nums[k]});
            }
        }
    }
    return sz;
}

#endif //ALGORITHM_THREESUM_H
