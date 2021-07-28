//
// Created by Administrator on 2021/7/28.
//

#ifndef ALGORITHM_MAXIMUMGAP_H
#define ALGORITHM_MAXIMUMGAP_H

/**
 * 164. 最大间距
 *  给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。如果数组元素个数小于 2，则返回 0。
 *
 * 示例 1:
 *  输入: [3,6,9,1]
 *  输出: 3
 *  解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
 *
 * 示例 2:
 *  输入: [10]
 *  输出: 0
 *  解释: 数组元素个数小于 2，因此返回 0。
 *
 *
 * 求解策略:
 *  1. 排序: 排序并迭代数组, 返回相邻元素的最大差值
 */

#include <vector>

using namespace std;

int maximumGap(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int diff = 0;
    for (int i = 1; i < nums.size(); ++i) {
        diff = max(diff, nums[i] - nums[i - 1]);
    }
    return diff;
}

#endif //ALGORITHM_MAXIMUMGAP_H
