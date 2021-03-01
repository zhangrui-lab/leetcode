//
// Created by 张锐 on 2021/3/1.
//

#ifndef ALGORITHM_MAJORITYELEMENT_H
#define ALGORITHM_MAJORITYELEMENT_H

/*
 * 169. 多数元素
 *  给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 *  你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 *  
 * 1. 暴力求解
 * 2. 计数优化 todo
 */

#include <map>
#include <vector>

int majorityElement(std::vector<int> &nums) {
    std::map<int, int> count;
    for (int i = 0; i < nums.size(); ++i) {
        count[nums[i]]++;
    }
    for (auto iter = count.cbegin(); iter != count.cend(); iter++) {
        if (iter->second > nums.size() / 2)
            return iter->first;
    }
    return INT_MIN;
}

#endif //ALGORITHM_MAJORITYELEMENT_H
