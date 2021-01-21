//
// Created by 张锐 on 2021/1/18.
//

#ifndef ALGORITHM_MAXIMUMSUBARRAY_H
#define ALGORITHM_MAXIMUMSUBARRAY_H
/*
 * 最大子序和
 *  给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 动态规划
 *  dp[i]为以nums[i]结尾的子数组的最大和。
 *  maxSubArray(nums) = dp[i]; (for i=0 to n)
 *  dp[i] = nums[i];          (i!=0 && dp[i-1] <= 0)
 *        = nums[i]+dp[i-1];  (i!=0 && dp[i-1] > 0)
 *        = nums[0];          (i=0)
 *
 * 数学归纳法求解
 *
 */

#include <vector>

int maxSubArray2(std::vector<int> &nums) {
    if (nums.empty())
        return 0;
    int dp[nums.size()], sum = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
        sum = std::max(sum, dp[i]);
    }
    return sum;
}

#endif //ALGORITHM_MAXIMUMSUBARRAY_H
