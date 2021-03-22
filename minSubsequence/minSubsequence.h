//
// Created by 张锐 on 2021/3/22.
//

#ifndef ALGORITHM_MINSUBSEQUENCE_H
#define ALGORITHM_MINSUBSEQUENCE_H

/*
 * 1403. 非递增顺序的最小子序列
 *  给你一个数组 nums，请你从中抽取一个子序列，满足该子序列的元素之和严格大于未包含在该子序列中的各元素之和。
 *  如果存在多个解决方案，只需返回长度最小的子序列。如果仍然有多个解决方案，则返回元素之和最大的子序列。
 *  与子数组不同的地方在于，「数组的子序列」不强调元素在原数组中的连续性，也就是说，它可以通过从数组中分离一些（也可能不分离）元素得到。
 *  注意，题目数据保证满足所有约束条件的解决方案是唯一的。同时，返回的答案应当按非递增顺序排列。
 * eg:
 *  输入：nums = [4,3,10,9,8]
 *  输出：[10,9]
 *  解释：子序列 [10,9] 和 [10,8] 是最小的、满足元素之和大于其他各元素之和的子序列。但是 [10,9] 的元素之和最大。
 *
 *  输入：nums = [4,4,7,6,7]
 *  输出：[7,7,6]
 *  解释：子序列 [7,7] 的和为 14 ，不严格大于剩下的其他元素之和（14 = 4 + 4 + 6）。因此，[7,6,7] 是满足题意的最小子序列。注意，元素按非递增顺序返回。
 *
 * 1. 倒序排序数组: 并从前往后选取，直到前缀和大于后缀和
 */

#include <vector>
#include <algorithm>

std::vector<int> minSubsequence(std::vector<int> &nums) {
    int sSum = 0, pSum = 0, n = nums.size(), i = 0;
    std::sort(nums.begin(), nums.end(), [](int n1, int n2) { return n1 >= n2; });
    for (int i = 0; i < n; ++i)
        sSum += nums[i];
    for (; i < n && pSum <= sSum; ++i) {
        pSum += nums[i];
        sSum -= nums[i];
    }
    nums.resize(i);
    return nums;
}


std::vector<int> minSubsequence2(std::vector<int> &nums) {
    sort(nums.begin(), nums.end(), std::greater<int>());
    int sum = 0, ts = 0;
    for (auto v : nums) {
        sum += v;
    }
    for (int i = 0; i < nums.size(); i++) {
        ts += nums[i];
        if (ts > sum - ts) {
            return std::vector<int>(nums.begin(), nums.begin() + i + 1);
        }
    }
    return nums;
}

#endif //ALGORITHM_MINSUBSEQUENCE_H
