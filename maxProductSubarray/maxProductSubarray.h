//
// Created by Administrator on 2021/7/21.
//

#ifndef ALGORITHM_MAXPRODUCTSUBARRAY_H
#define ALGORITHM_MAXPRODUCTSUBARRAY_H

/**
 * 152. 乘积最大子数组
 *  给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 *
 * 示例 1:
 *  输入: [2,3,-2,4]
 *  输出: 6
 *  解释: 子数组 [2,3] 有最大乘积 6。
 *
 * 示例 2:
 *  输入: [-2,0,-1]
 *  输出: 0
 *  解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 *
 * 求解思路:
 *  1. 蛮力策略: 获取所有可能的子数组并求和, 返回其中最大值.
 *  2. 动态规划
 *  3. 分治策略:
 *      a. 寻找数组中间元素 mid, 将数组拆分为 left, right.
 *      b. 最大子数组可能包含 mid, 在 left 中, 在 right 中.
 */

#include <vector>

using namespace std;

int maxProductSubarray(vector<int> &nums) {
    int maxVal = INT_MIN;
    for (int i = 0, l = nums.size(); i < l; ++i) {
        int tmp = nums[i], tmpMax = tmp;
        for (int j = i + 1; j < nums.size(); ++j) {
            tmpMax = max(tmpMax, (tmp = tmp * nums[j]));
        }
        maxVal = max(maxVal, tmp);
    }
    return maxVal;
}

int maxProductSubarray2(vector<int> &nums) {
    vector<int> maxF(nums), minF(nums);
    for (int i = 1; i < nums.size(); ++i) {
        maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
        minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
    }
    return *max_element(maxF.begin(), maxF.end());
}

int maxProductSubarray3(vector<int> &nums) {
    int maxF = nums[0], minF = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int mx = maxF, mn = minF;
        maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
        minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
        ans = max(maxF, ans);
    }
    return ans;
}

#endif //ALGORITHM_MAXPRODUCTSUBARRAY_H
