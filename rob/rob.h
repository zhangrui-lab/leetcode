//
// Created by Administrator on 2021/7/23.
//

#ifndef ALGORITHM_ROB_H
#define ALGORITHM_ROB_H

/**
 * 198. 打家劫舍
 *  你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 *  给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 * 示例 1：
 *  输入：[1,2,3,1]
 *  输出：4
 *  解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。 偷窃到的最高金额 = 1 + 3 = 4 。
 *
 * 示例 2：
 *  输入：[2,7,9,3,1]
 *  输出：12
 *  解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 *
 * 求解策略:
 *  1. DFS: 遍历所有可能的偷盗方案, 找到最大值.
 *  2. 使用记忆优化的DFS: 保存偷第i家与不偷第i家情况下后续所能偷到的最大值
 *  3. 动态规划
 *  4. 滚动数组优化存储空间
 */

#include <map>
#include <vector>

using namespace std;

void rob(vector<int> &nums, int curr, int index, int &maxVal) {
    if (index >= nums.size()) {
        maxVal = max(maxVal, curr);
        return;
    }
    rob(nums, curr + nums[index], index + 2, maxVal);
    rob(nums, curr, index + 1, maxVal);
}


int rob(vector<int> &nums) {
    int maxVal = INT_MIN;
    rob(nums, 0, 0, maxVal);
    return maxVal;
}

int rob2(vector<int> &nums, int i, bool issteal, vector<int> &st, vector<int> &nst) {
    if (i >= nums.size())
        return 0;
    else if (issteal) {
        if (nst[i + 1] == -1) nst[i + 1] = rob2(nums, i + 1, false, st, nst);
        return nst[i + 1];
    } else {
        if (st[i + 1] == -1) st[i + 1] = rob2(nums, i + 1, true, st, nst);
        if (nst[i + 1] == -1) nst[i + 1] = rob2(nums, i + 1, false, st, nst);
        return max(st[i + 1] + nums[i], nst[i + 1]);
    }
}

int rob2(vector<int> &nums) {
    int size = nums.size();
    vector<int> st(size, -1), nst(size, -1);
    return rob2(nums, 0, false, st, nst);
}

int rob3(vector<int> &nums) {
    int size = nums.size();
    if (size < 2) {
        return size ? nums[0] : 0;
    }
    vector<int> dp(size, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < size; ++i) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[size - 1];
}

int rob4(vector<int> &nums) {
    int size = nums.size();
    if (size < 2) {
        return size ? nums[0] : 0;
    }
    int p1 = nums[0], p2 = max(nums[0], nums[1]), tmp;
    for (int i = 2; i < size; ++i) {
        tmp = p2;
        p2 = max(nums[i] + p1, p2);
        p1 = tmp;
    }
    return p2;
}

#endif //ALGORITHM_ROB_H
