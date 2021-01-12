//
// Created by 张锐 on 2021/1/12.
//

#ifndef ALGORITHMS_FOURSUM_H
#define ALGORITHMS_FOURSUM_H

/*
 * 四数之和
 *
 * 蛮力求解
 * 枚举所有可能的四位数组合，返回和为目标值的数位组合。
 *
 * 优化策略1：同三数之和，合并最后两层的迭代
 */

#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum1(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> maybes;
    size_t size = nums.size();
    for (int i = 0; i < size; ++i) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;  // 跳过重复元素
        for (int j = i + 1; j < size; ++j) {
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;
            for (int k = j + 1; k < size; ++k) {
                if (k != j + 1 && nums[k] == nums[k - 1]) continue;
                for (int l = k + 1; l < size; ++l) {
                    if (l != k + 1 && nums[l] == nums[l - 1]) continue;
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        maybes.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
    }
    return maybes;
}

std::vector<std::vector<int>> fourSum2(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> maybes;
    size_t size = nums.size();
    for (int i = 0; i < size; ++i) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;  // 跳过重复元素
        for (int j = i + 1; j < size; ++j) {
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;
            int k = j + 1, l = size - 1;
            while (k < l) {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                // k,j 均不为已考察过的重复元素且和为0时，加入结果集中
                if (sum == target) {
                    maybes.push_back({nums[i], nums[j], nums[k], nums[l]});
                    int l0 = l - 1, k0 = k + 1; // 获取下一个可能的比较值
                    while (k < l0 && nums[l0] == nums[l]) {
                        --l0;
                    }
                    l = l0;
                    while (k0 < l && nums[k0] == nums[k]) {
                        ++k0;
                    }
                    k = k0;
                    if (k >= l)
                        break;
                } else if (sum > target) {
                    --l;
                } else {
                    ++k;
                }
            }
        }
    }
    return maybes;
}

#endif //ALGORITHMS_FOURSUM_H
