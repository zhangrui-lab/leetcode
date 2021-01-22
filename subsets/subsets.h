//
// Created by 张锐 on 2021/1/22.
//

#ifndef ALGORITHM_SUBSETS_H
#define ALGORITHM_SUBSETS_H

/*
 * 78. 子集
 *  给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。解集不能包含重复的子集。你可以按任意顺序 返回解集。
 *
 *
 * 所有可能的子集,典型的DFS
 * 给定集合的n个元素是否出现,n位长的01串的所有可能情况
 */

#include <vector>

void subsets1(int index, std::vector<int> &nums, std::vector<int> &curr, std::vector<std::vector<int>> &ans) {
    if (index >= nums.size()) {
        ans.push_back(curr);
        return;
    }
    subsets1(index + 1, nums, curr, ans);
    curr.push_back(nums[index]);
    subsets1(index + 1, nums, curr, ans);
    curr.pop_back();
}

std::vector<std::vector<int>> subsets1(std::vector<int> &nums) {
    std::vector<std::vector<int>> ans;
    std::vector<int> curr;
    subsets1(0, nums, curr, ans);
    return ans;
}

std::vector<std::vector<int>> subsets2(std::vector<int> &nums) {
    std::vector<std::vector<int>> ans;
    int n = nums.size(), end = 1 << n;
    for (int start = 0; start < end; ++start) {
        std::vector<int> tmp;
        for (int i = 0; i < nums.size(); ++i)
            if (start & (1 << i))
                tmp.push_back(nums[i]);
        ans.push_back(tmp);
    }
    return ans;
}


#endif //ALGORITHM_SUBSETS_H
