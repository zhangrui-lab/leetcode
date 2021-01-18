//
// Created by 张锐 on 2021/1/18.
//

#ifndef ALGORITHM_PERMUTATIONS_H
#define ALGORITHM_PERMUTATIONS_H

/*
 * 全排列
 *
 * 1. 不断获取下一排列，直至元素排列和当前一致
 * 2. dfs遍历所有情况
 *  每一步都有可能面临多个选择(前置的选择会影响后续的选择)。我们尽可能的作出选择，达到基本情况。并在此基础上不断的尝试剪枝和回溯。
 * 3. dfs优化，使用输入序列来替代已使用元素标记，降低空间复杂度。
 */

#include <vector>
#include <algorithm>
#include <unordered_map>
#include "../nextPermutation/nextPermutation.h"

std::vector<std::vector<int>> permute1(std::vector<int> &nums) {
    std::vector<std::vector<int>> arrangements;
    std::vector<int> source = nums;
    do {
        arrangements.push_back(nums);
        nextPermutation2(nums);
    } while (!std::equal(nums.cbegin(), nums.cend(), source.cbegin()));
    return arrangements;
}

void permute2(std::unordered_map<int, int> &count, std::vector<std::vector<int>> &arrangements, std::vector<int> &curr,
              int len) {
    if (curr.size() == len) {
        arrangements.push_back(curr);
        return;
    }
    for (auto iter = count.begin(); iter != count.end(); iter++) {
        if (iter->second == 1)
            continue;
        curr.push_back(iter->first);
        iter->second = 1;
        permute2(count, arrangements, curr, len);
        curr.pop_back();
        iter->second = 0;
    }

}
std::vector<std::vector<int>> permute2(std::vector<int> &nums) {
    std::vector<std::vector<int>> arrangements;
    std::unordered_map<int, int> count;
    std::vector<int> curr;
    for (int i = 0; i < nums.size(); ++i)
        count[nums[i]] = 0;
    permute2(count, arrangements, curr, nums.size());
    return arrangements;
}

void backtrack(std::vector<std::vector<int>> &res, std::vector<int> &output, int first, int len) {
    // 所有数都填完了
    if (first == len) {
        res.emplace_back(output);
        return;
    }
    for (int i = first; i < len; ++i) {
        // 动态维护数组
        std::swap(output[i], output[first]);
        // 继续递归填下一个数
        backtrack(res, output, first + 1, len);
        // 撤销操作
        std::swap(output[i], output[first]);
    }
}
std::vector<std::vector<int>> permute3(std::vector<int> &nums) {
    std::vector<std::vector<int> > res;
    backtrack(res, nums, 0, (int) nums.size());
    return res;
}

#endif //ALGORITHM_PERMUTATIONS_H
