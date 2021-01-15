//
// Created by 张锐 on 2021/1/15.
//

#ifndef ALGORITHM_FIRSTMISSINGPOSITIVE_H
#define ALGORITHM_FIRSTMISSINGPOSITIVE_H

/*
 * 缺失的第一个正数
 *  给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 *  进阶：你可以实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案吗？
 *
 * 1. 使用 HASHMAP 标记元素
 * 2. 置换法：将原始值 x 的位置x-1标记为负数，表示此位置 i 对应的元素 i+1 已出现。
 * 3. 置换法: 假设序列占据 1....n-1, 则缺失的第一个正数为n。不妨将元素恢复为第i位值为i+1的形式。第一个不匹配的元素为缺失元素。
 *
 */

#include <vector>
#include <unordered_set>

int firstMissingPositive(std::vector<int> &nums) {
    std::unordered_set<int> hash;
    for (int i = 0; i < nums.size(); ++i)
        hash.insert(nums[i]);
    int i = 1;
    while (hash.find(i) != hash.cend()) i++;
    return i;
}


int firstMissingPositive1(std::vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[nums[i] - 1], nums[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int firstMissingPositive2(std::vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        nums[i] = nums[i] <= 0 ? n + 1 : nums[i];
    }
    for (int i = 0; i < n; ++i) {
        if (std::abs(nums[i]) <= n) {
            nums[std::abs(nums[i]) - 1] = -nums[std::abs(nums[i]) - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }
    return n + 1;
}


#endif //ALGORITHM_FIRSTMISSINGPOSITIVE_H
