//
// Created by Administrator on 2021/7/23.
//

#ifndef ALGORITHM_ROB_H
#define ALGORITHM_ROB_H

/**
 * 213. 打家劫舍 II
 *  你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
 *  同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 *
 * 求解策略:
 *  1. dfs: 对任意房屋选择偷或者不偷. 返回在不报警情况下的最高金额.
 *      f(nums, pos) 表示从nums的pos开始进行偷窃时所能在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 *      f(nums, pos) = max(f(nums, pos+2)+currStoredVal, f(nums, pos+1));
 *          currStoredVal表示当前节点所偷金额 (在偷第一个房屋时, 最后一个房屋只能偷0)
 *  2. 使用记忆优化的DFS
 *  3. 动态规划
 */

#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

int rob(vector<int> &nums, bool stealFirst = false, int pos = 0) {
    if (pos >= nums.size()) return 0;
    int val = (pos == nums.size() - 1 && stealFirst) ? 0 : nums[pos];
    return max(val + rob(nums, pos == 0 ? true : stealFirst, pos + 2),
               rob(nums, pos == 0 ? false : stealFirst, pos + 1));
}

int robRange(vector<int> &nums, int start, int end) {
    int first = nums[start], second = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++) {
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}

int rob3(vector<int> &nums) {
    int length = nums.size();
    if (length == 1) {
        return nums[0];
    } else if (length == 2) {
        return max(nums[0], nums[1]);
    }
    return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
}

#endif //ALGORITHM_ROB_H
