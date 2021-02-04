//
// Created by 张锐 on 2021/2/4.
//

#ifndef ALGORITHM_LONGESTCONSECUTIVE_H
#define ALGORITHM_LONGESTCONSECUTIVE_H

/*
 * 128. 最长连续序列
 *  给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *  进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？
 * eg
 *  输入：nums = [100,4,200,1,3,2]
 *  输出：4
 *  解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * ===========
 *
 * 1. 排序获取最长的连续序列
 * 2. hash表解决当前问题
 *  用集合存储序列元素。 假设序列中元素存在多个不连续的连续子序列，从每一子序列的最小元素开始访问其最大长度。
 */

#include <vector>
#include <algorithm>
#include <unordered_set>

int longestConsecutive1(std::vector<int> &nums) {
    if (nums.empty())
        return 0;
    std::sort(nums.begin(), nums.end());
    int max = 1, cur = 1, i, j;
    for (i = 0, j = i; j < nums.size(); ++j) {
        if (nums[i] == nums[j])
            continue;
        if (nums[i] + 1 == nums[j]) {
            ++cur;
            max = std::max(max, cur);
        } else {
            cur = 1;
        }
        i = j;
    }
    return max;
}


int longestConsecutive2(std::vector<int> &nums) {
    std::unordered_set<int> numSet;
    for (const auto &num : nums)
        numSet.insert(num);
    int max = 0;
    for (int num: numSet) {
        max = std::max(max, 1);
        if (numSet.count(num - 1))
            continue;
        int curr = 1;
        while (numSet.count(num + 1)) {
            curr++;
            num++;
        }
        max = std::max(max, curr);
    }
    return max;
}


#endif //ALGORITHM_LONGESTCONSECUTIVE_H
