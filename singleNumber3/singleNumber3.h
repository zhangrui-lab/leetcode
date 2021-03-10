//
// Created by 张锐 on 2021/3/10.
//

#ifndef ALGORITHM_SINGLENUMBER1_H
#define ALGORITHM_SINGLENUMBER1_H

/*
 * 260. 只出现一次的数字 III
 *  给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按任意顺序返回答案。
 *  进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
 *
 * 1. map
 * 2. set
 * 3. 分组异或
 *  把所有数字分成两组，使得：
 *      两个只出现一次的数字在不同的组中；
 *      相同的数字会被分到相同的组中。
 *  那么对两个组分别进行异或操作，即可得到答案的两个数字。这是解决这个问题的关键。
 *  算法
 *      先对所有数字进行一次异或，得到两个出现一次的数字的异或值。
 *      在异或结果中找到任意为 1 的位。
 *      根据这一位对所有的数字进行分组。
 *      在每个组内进行异或操作，得到两个数字。
 */

#include <vector>
#include <unordered_map>
#include <unordered_set>

std::vector<int> singleNumber(std::vector<int> &nums) {
    std::vector<int> ans;
    std::unordered_map<int, int> count;
    for (auto num: nums)
        count[num]++;
    for (auto iter = count.cbegin(); iter != count.cend(); iter++)
        if (iter->second == 1)
            ans.push_back(iter->first);
    return ans;
}

std::vector<int> singleNumber1(std::vector<int> &nums) {
    std::vector<int> ans;
    std::unordered_set<int> single;
    for (auto num:nums)
        if (single.count(num))
            single.erase(num);
        else
            single.insert(num);
    for (auto iter = single.cbegin(); iter != single.cend(); iter++)
        ans.push_back(*iter);
    return ans;
}

std::vector<int> singleNumber2(std::vector<int> &nums) {
    int ret = 0, g1 = 0, g2 = 0;
    for (auto num: nums)
        ret ^= num;
    ret &= -ret;
    for (auto num : nums) {
        if (num & (1 << ret))
            g1 ^= num;
        else
            g2 ^= num;
    }
    return {g1, g2};
}

#endif //ALGORITHM_SINGLENUMBER1_H
