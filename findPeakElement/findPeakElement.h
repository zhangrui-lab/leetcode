//
// Created by Administrator on 2021/7/28.
//

#ifndef ALGORITHM_FINDPEAKELEMENT_H
#define ALGORITHM_FINDPEAKELEMENT_H

/**
 * 162. 寻找峰值
 *  峰值元素是指其值大于左右相邻值的元素。
 *  给你一个输入数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 *  你可以假设 nums[-1] = nums[n] = -∞ 。
 *
 * 示例 1：
 *  输入：nums = [1,2,3,1]
 *  输出：2
 *  解释：3 是峰值元素，你的函数应该返回其索引 2。
 *
 * 示例 2：
 *  输入：nums = [1,2,1,3,5,6,4]
 *  输出：1 或 5
 *  解释：你的函数可以返回索引 1，其峰值元素为 2；或者返回索引 5， 其峰值元素为 6。
 *
 * 求解策略:
 *  1. 线性扫描: 迭代输入序列,若已遍历部分单调递增时不断向前,直至出现一次递减. 则后继元素为递减的元素为峰值.  O(n)
 *  2. DFS (算法同 1)
 *  3. 递归二分查找: 对于给定的节点x,与其后继节点y判断当前局部的上升下降情况. 当xy递增时,在x右侧必定存在峰值. 当xy递减时, 在x左侧必定出现峰值.
 *  3. 迭代二分查找 (同3)
 */

#include <vector>

using namespace std;

int findPeakElement(vector<int> &nums) {
    nums.push_back(INT_MIN);
    for (int i = 1, size = nums.size(); i < size; i++)
        if (nums[i - 1] > nums[i])
            return i - 1;
    return nums.size() == 2 ? 0 : -1;
}

int findPeakElement2(vector<int> &nums, int pos) {
    return pos == nums.size() ? -1 : (nums[pos - 1] > nums[pos] ? pos - 1 : findPeakElement2(nums, pos + 1));
}

int findPeakElement2(vector<int> &nums) {
    if (nums.size() < 2)
        return nums.size() - 1;
    nums.push_back(INT_MIN);
    return findPeakElement2(nums, 1);
}

int findPeakElement3(vector<int> &nums, int l, int r) {
    if (l == r) {
        return l;
    }
    int m = (l + r) >> 1;
    if (nums[m] > nums[m + 1])
        return findPeakElement3(nums, l, m);
    return findPeakElement3(nums, m + 1, r);

}

int findPeakElement3(vector<int> &nums) {
    return findPeakElement3(nums, 0, nums.size() - 1);
}

int findPeakElement4(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, m;
    while (l != r) {
        m = (l + r) >> 1;
        if (nums[m] > nums[m + 1])
            r = m;
        else
            l = m + 1;
    }
    return l;
}

#endif //ALGORITHM_FINDPEAKELEMENT_H
