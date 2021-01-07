//
// Created by 张锐 on 2021/1/7.
//

#ifndef ALGORITHMS_TWOSUM_H
#define ALGORITHMS_TWOSUM_H

#include <utility>
#include <vector>
#include <map>
#include <set>

/*
 * nums: [ 1, 3, 4, 6, 7, 8 ]; target: 10
 */

// O(n^2)
std::pair<int, int> twoSum1(std::vector<int> &nums, int target) {
    int i, j;
    for (i = 0; i < nums.size(); ++i) {
        for (j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// O(n)
std::pair<int, int> twoSum2(std::vector<int> &nums, int target) {
    std::map<int, int> difference;
    std::map<int, int>::const_iterator iter;
    for (int i = 0; i < nums.size(); ++i) {
        if ((iter = difference.find(nums[i])) != difference.cend()) {
            return {difference[nums[i]], i};
        }
        difference[target - nums[i]] = i;
    }
    return {-1, -1};
}

// 输入序列有序时; O(n)
std::pair<int, int> twoSum3(std::vector<int> &nums, int target) {
    size_t lo = 0, hi = nums.size() - 1;
    while (lo != hi) {
        if (nums[lo] + nums[hi] == target) {
            return {lo, hi};
        } else {
            nums[lo] + nums[hi] < target ? ++lo : --hi;
        }
    }
    return {-1, -1};
}

#endif //ALGORITHMS_TWOSUM_H
