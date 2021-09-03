//
// Created by Administrator on 2021/9/3.
//

#ifndef ALGORITHM_ROTATE_H
#define ALGORITHM_ROTATE_H

/*
 * 189. 旋转数组
 *  给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 进阶：
 *  尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。 你可以使用空间复杂度为 O(1) 的 原地算法解决这个问题吗？
 *
 * 求解策略:
 *  1. 额外空间转存
 *  2. 库函数
 *  3. ..
 *  4. 环状替换
 *  5. 数组翻转
 */

#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int> &nums, int k) {
    k %= nums.size();
    vector<int> ans(nums.size());
    move(nums.begin(), nums.end() - k, move(nums.end() - k, nums.end(), ans.begin()));
    nums = ans;
}

void rotate2(vector<int> &nums, int k) {
    k %= nums.size();
    std::rotate(nums.begin(), nums.end() - k, nums.end());
}

void rotate3(vector<int> &nums, int k) {
    k %= nums.size();
    int end = nums.size(), i = 0, mid = end - k, j = mid;
    while (i != end - 1 && j != end) {
        swap(nums[i++], nums[j++]);
        if (i == mid) {
            printf("i:%d, mid:%d, j:%d  =>", i, mid, j);
            mid = j;
            printf("i:%d, mid:%d, j:%d\n", i, mid, j);
        }
        if (j == end) {
            printf("i:%d, mid:%d, j:%d  =>", i, mid, j);
            j = mid;
            printf("i:%d, mid:%d, j:%d\n", i, mid, j);
        }
    }
}

void rotate4(vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n;
    int count = gcd(k, n);
    for (int start = 0; start < count; ++start) {
        int current = start;
        int prev = nums[start];
        do {
            int next = (current + k) % n;
            swap(nums[next], prev);
            current = next;
        } while (start != current);
    }
}

void rotate5(vector<int> &nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

#endif //ALGORITHM_ROTATE_H
