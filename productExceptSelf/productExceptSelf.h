//
// Created by 张锐 on 2021/3/23.
//

#ifndef ALGORITHM_PRODUCTEXCEPTSELF_H
#define ALGORITHM_PRODUCTEXCEPTSELF_H

/*
 * 238. 除自身以外数组的乘积
 *  给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
 * eg:
 *  输入: [1,2,3,4]
 *  输出: [24,12,8,6]
 *
 * 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
 *  说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 进阶：
 *  你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 *
 * 1. 使用除法的情况
 *  求数组整体积 multiplicative。输出数组 output[i] = multiplicative/nums[i]
 *
 * 2. 不使用除法: 对任意位置 output[j] = for i=0 to n-1: { if (i != j) output[j]*=nums[i]; }
 *
 * 3. 左右乘积列表
 *
 * 4. 常数空间复杂度
 */

#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums) {
    int multiplicative = 1, zeroNum = 0;
    for (auto num:nums) {
        zeroNum += num == 0;
        multiplicative *= num == 0 ? 1 : num;
    }
    for (int i = 0, n = nums.size(); i < n; ++i)
        nums[i] = zeroNum ? (zeroNum > 1 ? 0 : (nums[i] == 0 ? multiplicative : 0)) : multiplicative / nums[i];
    return nums;
}

std::vector<int> productExceptSelf2(std::vector<int> &nums) {
    std::vector<int> ans(nums.size(), 1);
    for (int i = 0, n = nums.size(); i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (j != i)
                ans[i] *= nums[j];
        }
    return ans;
}

std::vector<int> productExceptSelf3(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> lProduct(n, 1), rProduct(n, 1);
    for (int i = 0, j = n - 1 - i; i < n; ++i, j = n - 1 - i) {
        lProduct[i] = i == 0 ? nums[0] : lProduct[i - 1] * nums[i];
        rProduct[j] = j == n - 1 ? nums[n - 1] : rProduct[j + 1] * nums[j];
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            nums[i] = rProduct[i + 1];
        } else if (i == n - 1) {
            nums[i] = lProduct[i - 1];
        } else {
            nums[i] = lProduct[i - 1] * rProduct[i + 1];
        }
    }
    return nums;
}

std::vector<int> productExceptSelf4(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> ans(n, 1);
    int prefix = 1, suffix = 1;
    for (int i = 0; i < n; i++) {
        ans[i] *= prefix;
        ans[n - i - 1] *= suffix;
        prefix *= nums[i];
        suffix *= nums[n - i - 1];
    }
    return ans;
}

// 此代码优化后可得到 productExceptSelf4
std::vector<int> productExceptSelf5(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> ans(n, 1);
    int prefix = 1, suffix = 1;
    for (int i = 0; i < n; i++) {
        ans[i] *= prefix;
        prefix *= nums[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= suffix;
        suffix *= nums[i];
    }
    return ans;
}

#endif //ALGORITHM_PRODUCTEXCEPTSELF_H