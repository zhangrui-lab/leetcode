//
// Created by 张锐 on 2021/1/15.
//

#ifndef ALGORITHM_COMBINATIONSUM_H
#define ALGORITHM_COMBINATIONSUM_H

/*
 * 组合总和
 *  给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。candidates 中的数字可以无限制重复被选取。
 *
 * DFS策略查看所有可能的情况
 */

#include <vector>
#include <unordered_set>


void combinationSum1(std::vector<int> &candidates, int target, int index, std::vector<std::vector<int>> &resu, std::vector<int> curr) {
    if (target == 0) {
        resu.push_back(curr);
        return;
    }
    for (int i = index; i < candidates.size(); ++i) {
        if (target - candidates[i] < 0)
            continue;
        curr.push_back(candidates[i]);
        combinationSum1(candidates, target - candidates[i], i, resu, curr);
        curr.pop_back();
    }
}
std::vector<std::vector<int>> combinationSum1(std::vector<int> &candidates, int target) {
    std::vector<std::vector<int>> resu;
    std::vector<int> curr;
    combinationSum1(candidates, target, 0, resu, curr);
    return resu;
}

void combinationSum(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& ans, std::vector<int>& combine, int idx) {
    if (idx == candidates.size()) {
        return;
    }
    if (target == 0) {
        ans.emplace_back(combine);
        return;
    }
    // 直接跳过
    combinationSum(candidates, target, ans, combine, idx + 1);
    // 选择当前数
    if (target - candidates[idx] >= 0) {
        combine.emplace_back(candidates[idx]);
        combinationSum(candidates, target - candidates[idx], ans, combine, idx);
        combine.pop_back();
    }
}
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> ans;
    std::vector<int> combine;
    combinationSum(candidates, target, ans, combine, 0);
    return ans;
}


#endif //ALGORITHM_COMBINATIONSUM_H
