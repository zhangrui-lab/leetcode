//
// Created by Administrator on 2021/9/26.
//

#ifndef ALGORITHM_LENGTHOFLIS_H
#define ALGORITHM_LENGTHOFLIS_H

// dfs: 考察所有可能的最长上升子序列，并获取最长值。
// dfs记忆化： dfs[i][j]为从i~n，已j作为开头的最长值，dfs[1][0]为原问题解。 dfs[i][j]= max( dp[i][j], 1+dfs[i+1][i], dfs[i+1][j] )
// dfs转dp： i从n~1，j从0~i进行迭代。
// 空间复杂度优化：上述dfs方程中，dfs[i][j]仅依赖于i+1行右侧的值。故可只用一行保存dfs。 dfs[j] = max( 1 + dfs[i], dfs[j] )  (1 + dfs[i]: N[i] > N[j]时)

// dp[i] 定义为以i结束的最长值。 dp[i] = max(dp[i], dp[j] + 1) （j为考察1~i-1的所有可能， 获取最大值。 1 <= j < i && nums[j] < nums[i]）
// O(nlgn)复杂度优化：

#include <iostream>
#include <algorithm>

using namespace std;

#define NMAX 1010

int n, nums[NMAX], memo[NMAX][NMAX], dp[NMAX][NMAX], dp_opt[NMAX], slow[NMAX];

int dfs(int p, int pn = 0) {
    int len = 0;
    for (int i = p; i <= n; ++i) {
        if (nums[pn] >= nums[i]) continue;
        len = max(1 + dfs(i + 1, i), len);
    }
    return len;
}

int dfs_memo(int p, int pn = 0) {
    if (memo[p][pn]) return memo[p][pn];
    for (int i = p; i <= n; ++i) {
        if (nums[pn] >= nums[i]) continue;
        memo[p][pn] = max(1 + dfs(i + 1, i), memo[p][pn]);
    }
    return memo[p][pn];
}

int dodp() {
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            dp[i][j] = std::max(dp[i][j], std::max((nums[i] > nums[j] ? 1 + dp[i + 1][i] : 0), dp[i + 1][j]));
        }
    }
    return dp[1][0];
}

int dodp_endi() {
    dp_opt[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp_opt[i] = std::max(dp_opt[i], (nums[i] > nums[j] ? 1 + dp_opt[j] : 1));
        }
    }
    return dp_opt[n];
}

int dodp_endi_opt() {
    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (slow[p] < nums[i]) slow[++p] = nums[i];
        else slow[lower_bound(slow, slow + p, nums[i]) - slow] = nums[i];
    }
    return p;
}

int dodp_opt() {
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            dp_opt[j] = std::max(dp_opt[j], nums[i] > nums[j] ? 1 + dp_opt[i] : 0);
        }
    }
    return dp_opt[0];
}

int main_LIS() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> nums[i];
    printf("%d", dodp_endi_opt());
    return 0;
}

// leetcode
int lengthOfLIS(vector<int> &nums) {
    if (nums.empty()) return 0;
    vector<int> slow;
    for (int i = 0, n = nums.size(); i < n; ++i) {
        if (slow.empty() || slow.back() < nums[i]) slow.push_back(nums[i]);
        else slow[lower_bound(slow.cbegin(), slow.cend(), nums[i]) - slow.cbegin()] = nums[i];
    }
    return slow.size();
}

#endif //ALGORITHM_LENGTHOFLIS_H
