//
// Created by Administrator on 2021/7/26.
//

#ifndef ALGORITHM_CONTAINSDUPLICATE_H
#define ALGORITHM_CONTAINSDUPLICATE_H

/**
 * 217. 存在重复元素
 *  给定一个整数数组，判断是否存在重复元素。
 *  如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
 *
 * 示例 1:
 *  输入: [1,2,3,1]
 *  输出: true
 *
 * 示例 2:
 *  输入: [1,2,3,4]
 *  输出: false
 *
 * 求解策略:
 *  1. set,map
 *  2. sort
 */

#include <vector>
#include <set>

using namespace std;

bool containsDuplicate(vector<int> &nums) {
    set<int> count;
    for (int i = 0; i < nums.size(); ++i) {
        if (count.count(nums[i]))
            return true;
        count.insert(nums[i]);
    }
    return false;
}

bool containsDuplicate2(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i)
        if (nums[i] == nums[i - 1])
            return true;
    return false;
}

#endif //ALGORITHM_CONTAINSDUPLICATE_H
