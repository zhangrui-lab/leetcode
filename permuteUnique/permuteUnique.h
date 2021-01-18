//
// Created by 张锐 on 2021/1/18.
//

#ifndef ALGORITHM_PERMUTATIONS2_H
#define ALGORITHM_PERMUTATIONS2_H

/*
 * 全排列 II
 *  给定一个可包含重复数字的序列 nums ，按任意顺序返回所有不重复的全排列.
 *
 * 1. DFS策略。
 *  新增剪枝策略为：在同一层内不考虑重复元素。
 */

#include <vector>
#include <algorithm>

void permuteUnique2Backtrack(std::vector<int> &nums, std::vector<std::vector<int>> &ans, int idx, std::vector<int> &perm,
                        std::vector<int> &vis) {
    if (idx == nums.size()) {
        ans.emplace_back(perm);
        return;
    }
    for (int i = 0; i < (int) nums.size(); ++i) {
        if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
            continue;
        }
        perm.emplace_back(nums[i]);
        vis[i] = 1;
        permuteUnique2Backtrack(nums, ans, idx + 1, perm, vis);
        vis[i] = 0;
        perm.pop_back();
    }
}

std::vector<std::vector<int>> permuteUnique2(std::vector<int> &nums) {
    std::vector<std::vector<int>> ans;
    std::vector<int> perm;
    std::vector<int> vis;
    vis.resize(nums.size());
    std::sort(nums.begin(), nums.end());
    permuteUnique2Backtrack(nums, ans, 0, perm, vis);
    return ans;
}


#endif //ALGORITHM_PERMUTATIONS2_H
