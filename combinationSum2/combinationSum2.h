//
// Created by 张锐 on 2021/1/15.
//

#ifndef ALGORITHM_combinationSum22_H
#define ALGORITHM_combinationSum22_H


/*
 * 组合总和 II
 *  给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。candidates 中的每个数字在每个组合中只能使用一次。
 */

#include <vector>
#include <utility>

void combinationSum2(std::vector<int> &candidates, int target, int index, std::vector<std::vector<int>> &resu, std::vector<int> curr) {
    if (target == 0) {
        resu.push_back(curr);
        return;
    }
    for (int i = index; i < candidates.size(); ++i) {
        if (target - candidates[i] < 0 || (i > index && candidates[i] == candidates[i-1]))
            continue;
        curr.push_back(candidates[i]);
        combinationSum2(candidates, target - candidates[i], i+1, resu, curr);
        curr.pop_back();
    }
}
std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> resu;
    std::vector<int> curr;
    combinationSum2(candidates, target, 0, resu, curr);
    return resu;
}


#endif //ALGORITHM_combinationSum22_H
