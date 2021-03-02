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
 * 2. 计数优化
 *  众数数量多余一半，则计数时总数必定可以销掉其他非众数的计数且还有剩余。
 * 3. 排序取中
 *  对给定序列进行排序，因为众数的现次数大于 ⌊ n/2 ⌋ 的元素。故中位数必定为众数。
 * 4. 随机抽取
 *  随机选取一元素，验证是否为众数。若是，则返回。
 * 5. 分治策略
 *  众数在对数组进行均分后的两个子序列之一中必定也为众数。
 */

#include <map>
#include <vector>
#include <cassert>
#include <algorithm>

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

int majorityElement1(std::vector<int> &nums) {
    assert(!nums.empty());
    int prev = nums[0], count = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == prev)
            count++;
        else if (count == 0) {
            prev = nums[i];
            count = 1;
        } else {
            count--;
        }
    }
    return prev;
}

int majorityElement2(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    return *(nums.cbegin() + nums.size() / 2);
}

int majorityElement3(std::vector<int> &nums) {
    while (true) {
        int elem = nums[rand() % nums.size()];
        int count = 0;
        for (auto num: nums)
            count += elem == num;
        if (count > nums.size() / 2)
            return elem;
    }
}

int majorityElement4(std::vector<int> &nums, int lo, int hi) {
    if (hi - lo < 2)
        return nums[lo];
    int mid = (lo + hi) >> 1;
    int ml = majorityElement4(nums, lo, mid);
    int mr = majorityElement4(nums, mid, hi);
    auto merge = [](const std::vector<int> &nums, int ml, int mr) {
        int cl = 0, cr = 0;
        for (auto num: nums) {
            cl += num == ml;
            cr += num == mr;
        }
        return cl > cr ? ml : mr;
    };
    return merge(nums, ml, mr);
}

int majorityElement4(std::vector<int> &nums) {
    return majorityElement4(nums, 0, nums.size());
}

#endif //ALGORITHM_MAJORITYELEMENT_H
