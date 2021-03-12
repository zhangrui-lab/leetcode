//
// Created by 张锐 on 2021/3/12.
//

#ifndef ALGORITHM_NUMBEROFSUBARRAYS_H
#define ALGORITHM_NUMBEROFSUBARRAYS_H

/*
 * 1248. 统计「优美子数组」
 *  给你一个整数数组 nums 和一个整数 k。
 *  如果某个连续子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
 *  请返回这个数组中「优美子数组」的数目。
 * eg:
 *  输入：nums = [1,1,2,1,1], k = 3
 *  输出：2
 *  解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
 *
 *  输入：nums = [2,4,6], k = 1
 *  输出：0
 *  解释：数列中不包含任何奇数，所以不存在优美子数组。
 *
 *  输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 *  输出：16
 *
 * 1. 蛮力策略 O(n^3)
 *  子程序a: 获取数组的所有连续子数组。
 *  子程序b: 判断给定数组的奇数元素个数。
 * 2. 前缀和优化蛮力策略中的子程序b O(n^2)
 *  使用前缀和保存其前的奇数元素的数量。
 * 3. 问题转化为求差值为k的问题
 *  输入:   [2,2,2,1,2,2,1,2,2,2],k=2;
 *  前缀和: [0,0,0,0,1,1,1,2,2,2,2],k=2; // k元素之前有多少个1
 *  nums[i,j]. psum[j] - psum[i-1] == k
 *             psum[i-1] = psump[j] - k;
 * 4. 数学
 */

#include <vector>


int numberOfSubarrays(std::vector<int> &nums, int k) {
    auto oddNum = [](std::vector<int> &nums, int lo, int hi) {
        int num = 0;
        for (int i = lo; i < hi; ++i)
            num += nums[i] % 2;
        return num;
    };
    int num = 0;
    for (int i = 0, n = nums.size(); i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            num += oddNum(nums, i, j) == k;
    return num;
}

int numberOfSubarrays2(std::vector<int> &nums, int k) {
    std::vector<int> pSum(nums.size());
    for (int i = 0, n = nums.size(); i < n; i++)
        pSum[i] = i == 0 ? nums[i] % 2 : pSum[i - 1] + nums[i] % 2;
    int num = 0;
    for (int i = 0, n = nums.size(); i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            num += pSum[j - 1] - (i > 0 ? pSum[i - 1] : 0) == k;
    return num;
}

int numberOfSubarrays3(std::vector<int> &nums, int k) {
    std::vector<int> count(nums.size() + 1, 0);
    int psum = 0, num = 0;
    count[0] = 1;
    for (int i = 0, n = nums.size(); i < n; ++i) {
        psum += nums[i] & 1;
        num += psum >= k ? count[psum - k] : 0;
        count[psum]++;
    }
    return num;
}

int numberOfSubarrays4(std::vector<int> &nums, int k) {
    int n = (int) nums.size();
    int odd[n + 2], ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] & 1) odd[++cnt] = i;
    }
    odd[0] = -1, odd[++cnt] = n;
    for (int i = 1; i + k <= cnt; ++i) {
        ans += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
    }
    return ans;
}

#endif //ALGORITHM_NUMBEROFSUBARRAYS_H