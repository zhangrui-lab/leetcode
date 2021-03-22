//
// Created by 张锐 on 2021/3/22.
//

#ifndef ALGORITHM_COUNTARRANGEMENT_H
#define ALGORITHM_COUNTARRANGEMENT_H

/*
 * 526. 优美的排列
 *  假设有从 1 到 N 的 N 个整数，如果从这 N 个数字中成功构造出一个数组，使得数组的第 i 位 (1 <= i <= N) 满足如下两个条件中的一个，我们就称这个数组为一个优美的排列。条件：
 *  第 i 位的数字能被 i 整除
 *  i 能被第 i 位上的数字整除
 *  现在给定一个整数 N，请问可以构造多少个优美的排列？
 *
 * 1. 蛮力策略: 获取从 1 到 N 的 N 个整数的所有排列，并判定每个排列是否为优美的排列；
 *  蛮力算法中可优化的部分：
 *      1. 下一序列的构建
 *      2. 下一序列是否为优美排列的判断: 只对构建下一排列过程中改变的部分做验证
 *
 *
 */

#include <vector>
#include "../nextPermutation/nextPermutation.h"

int countArrangement(int n) {
    int ans = 1;
    std::vector<int> source(n), curr(n);
    for (int i = 1; i <= n; ++i) {
        source[i - 1] = i;
        curr[i - 1] = i;
    }
    auto isBeautiful = [](std::vector<int> &vec) {
        int beautiful = 1;
        for (int i = 0, n = vec.size(); beautiful && i < n; ++i)
            beautiful &= (vec[i] % (i + 1) == 0 || (i + 1) % vec[i] == 0);
        return beautiful;
    };
    nextPermutation2(curr);
    while (curr != source) {
        ans += isBeautiful(curr);
        nextPermutation2(curr);
    }
    return ans;
}

void permute(std::vector<int> &nums, int l, int &count) {
    if (l == nums.size()) {
        count++;
    }
    for (int i = l; i < nums.size(); i++) {
        std::swap(nums[i], nums[l]);
        if (nums[l] % (l + 1) == 0 || (l + 1) % nums[l] == 0)
            permute(nums, l + 1, count);
        std::swap(nums[i], nums[l]);
    }
}

int countArrangement2(int n) {
    int count = 0;
    std::vector<int> nums(n);
    for (int i = 1; i <= n; i++)
        nums[i - 1] = i;
    permute(nums, 0, count);
    return count;
}

#endif //ALGORITHM_COUNTARRANGEMENT_H
