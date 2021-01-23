//
// Created by 47302 on 2021/1/23.
//

#ifndef ALGORITHM_SUBSETSWITHDUP_H
#define ALGORITHM_SUBSETSWITHDUP_H

/*
 * 90. 子集 II
 *  给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。说明：解集不能包含重复的子集。
 *
 * 所有可能的情况:DFS深度优先
 * n位数二进制串的所有位组合。
 */

#include <vector>
#include <algorithm>

void subsetsWithDup1(int index, std::vector<int> &nums, std::vector<int> &curr, std::vector<std::vector<int>> &ans) {
    ans.push_back(curr);
    for (int i = index; i < nums.size(); ++i) {
        if (i > index && nums[i] == nums[i - 1]) {
            continue;
        }
        curr.push_back(nums[i]);
        subsetsWithDup1(i + 1, nums, curr, ans);
        curr.pop_back();
    }
}

std::vector<std::vector<int>> subsetsWithDup1(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> curr;
    std::vector<std::vector<int>> ans;
    subsetsWithDup1(0, nums, curr, ans);
    return ans;
}

#endif //ALGORITHM_SUBSETSWITHDUP_H
