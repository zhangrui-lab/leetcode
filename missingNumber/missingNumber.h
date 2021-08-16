//
// Created by Administrator on 2021/8/16.
//

#ifndef ALGORITHM_MISSINGNUMBER_H
#define ALGORITHM_MISSINGNUMBER_H

/**
 * 268. 丢失的数字
 *  给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
 *
 * 求解策略:
 *  1. 排序
 *  2. 哈希
 *  3. 位运算
 */

#include <vector>
#include <functional>
#include <unordered_set>

using namespace std;

int missingNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    if (nums[0] != 0)
        return 0;
    for (int i = 1, n = nums.size(); i < n; ++i) {
        if (nums[i - 1] != nums[i] - 1)
            return nums[i - 1] + 1;
    }
    return nums.size();
}

int missingNumber2(vector<int> &nums) {
    unordered_set<int> hash;
    for (int i = 0; i < nums.size(); i++)
        hash.insert(nums[i]);
    for (int i = 0; i <= nums.size(); i++)
        if (hash.find(i) == hash.cend())
            return i;
    return -1;
}

int missingNumber3(vector<int> &nums) {
    int missing = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        missing ^= i ^ nums[i];
    }
    return missing;
}

#endif //ALGORITHM_MISSINGNUMBER_H
