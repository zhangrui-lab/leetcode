//
// Created by 张锐 on 2021/1/12.
//

#ifndef ALGORITHMS_THREESUMCLOSEST_H
#define ALGORITHMS_THREESUMCLOSEST_H

/*
 * 最接近的三数之和
 *
 * 蛮力策略
 * 遍历所以可能的三位数组合，取其和并逐步更新和记录sum距离target最小者。
 *
 * 蛮力的优化策略
 * 排序输入序列，并合并地二,三个元素的迭代。顺序回去第二个元素b，并逆序获取第三个元素c。考虑当前 a+b+c的和与target的大小关系来迭代c的位置，使其和合理的逼近target；
 */

#include <vector>
#include <cmath>
#include <algorithm>

int threeSumClosest(std::vector<int> &nums, int target) {
    size_t size = nums.size();
    int absDiff = INT_MAX, sum = INT_MAX;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            for (int k = j + 1; k < size; ++k) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (absDiff > abs(target - tmp)) {
                    sum = tmp;
                    absDiff = abs(target - tmp);
                }
            }
        }
    }
    return sum;
}

int threeSumClosest1(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    size_t size = nums.size();
    int absDiff = INT_MAX, sum = INT_MAX;
    auto update = [&](int tmp) {
        if (absDiff > abs(target - tmp)) {
            sum = tmp;
            absDiff = abs(target - tmp);
        }
    };
    for (int i = 0; i < size; ++i) {
        int k = nums.size() - 1;
        for (int j = i + 1; j < size; ++j) {
            int tmp;
            while (j < k && (tmp = nums[i] + nums[j] + nums[k]) > target) {
                update(tmp);
                k--;
            }
            if (j == k) {
                break;
            }
            update(tmp);
        }
    }
    return sum;
}

int threeSumClosest2(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    int best = 1e7;

    // 根据差值的绝对值来更新答案
    auto update = [&](int cur) {
        if (abs(cur - target) < abs(best - target)) {
            best = cur;
        }
    };

    // 枚举 a
    for (int i = 0; i < n; ++i) {
        // 保证和上一次枚举的元素不相等
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        // 使用双指针枚举 b 和 c
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            // 如果和为 target 直接返回答案
            if (sum == target) {
                return target;
            }
            update(sum);
            if (sum > target) {
                // 如果和大于 target，移动 c 对应的指针
                int k0 = k - 1;
                // 移动到下一个不相等的元素
                while (j < k0 && nums[k0] == nums[k]) {
                    --k0;
                }
                k = k0;
            } else {
                // 如果和小于 target，移动 b 对应的指针
                int j0 = j + 1;
                // 移动到下一个不相等的元素
                while (j0 < k && nums[j0] == nums[j]) {
                    ++j0;
                }
                j = j0;
            }
        }
    }
    return best;
}


#endif //ALGORITHMS_THREESUMCLOSEST_H
