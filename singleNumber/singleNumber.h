//
// Created by 张锐 on 2021/2/5.
//

#ifndef ALGORITHM_SINGLENUMBER_H
#define ALGORITHM_SINGLENUMBER_H

/*
 * 136. 只出现一次的数字
 *  给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 说明：
 *  你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * eg
 *  输入: [2,2,1]
 *  输出: 1
 *
 * 1. HashMap: 查看每个元素出现的次数，并找出次数为1者
 * 2. Set: 集合中存放未重复出现的元素。
 * 3. Set 存储所有元素，return sum(Set) * 2 - sum(input);
 * 4. 位运算
 */

#include <vector>
#include <unordered_map>
#include <unordered_set>

int singleNumber1(std::vector<int> &nums) {
    std::unordered_map<int, int> count;
    for (int i = 0; i < nums.size(); ++i)
        count[nums[i]]++;
    for (auto iter = count.cbegin(); iter != count.cend(); ++iter) {
        if (iter->second == 1)
            return iter->first;
    }
    return -1;
}

int singleNumber2(std::vector<int> &nums) {
    std::unordered_set<int> unDup;
    for (int i = 0; i < nums.size(); ++i) {
        if (unDup.count(nums[i]))
            unDup.erase(nums[i]);
        else
            unDup.insert(nums[i]);
    }
    return *unDup.begin();
}

int singleNumber3(std::vector<int> &nums) {
    int unDupSum = 0, sum = 0;
    std::unordered_set<int> unDup;
    for (int i = 0; i < nums.size(); ++i) {
        if (!unDup.count(nums[i])) {
            unDup.insert(nums[i]);
            unDupSum += nums[i];
        }
        sum += nums[i];
    }
    return 2 * unDupSum - sum;
}

int singleNumber4(std::vector<int> &nums) {
    int num = 0;
    for (int i = 0; i < nums.size(); ++i)
        num ^= nums[i];
    return num;
}


#endif //ALGORITHM_SINGLENUMBER_H
