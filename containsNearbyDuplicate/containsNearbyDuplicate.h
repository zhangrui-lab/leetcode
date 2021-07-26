//
// Created by Administrator on 2021/7/26.
//

#ifndef ALGORITHM_CONTAINSNEARBYDUPLICATE_H
#define ALGORITHM_CONTAINSNEARBYDUPLICATE_H

/**
 * 219. 存在重复元素 II
 *  给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。
 *
 * 示例 1:
 *  输入: nums = [1,2,3,1], k = 3
 *  输出: true
 *
 * 示例 2:
 *  输入: nums = [1,2,3,1,2,3], k = 2
 *  输出: false
 */

#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> myMap;   //key是值，value保存的是下标
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {  //遍历nums
        if (myMap.count(nums[i]) != 0 && i - myMap[nums[i]] <= k)//查看是否存在
            return true;
        myMap[nums[i]] = i;    //存进哈希
    }
    return false;
}

#endif //ALGORITHM_CONTAINSNEARBYDUPLICATE_H
