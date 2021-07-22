//
// Created by Administrator on 2021/7/22.
//

#ifndef ALGORITHM_TWOSUM_H
#define ALGORITHM_TWOSUM_H

/**
 * 167. 两数之和 II - 输入有序数组
 *  给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
 *  函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。
 *  你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 *
 * 示例 1：
 *  输入：numbers = [2,3,4], target = 6
 *  输出：[1,3]
 *
 * 示例 2：
 *  输入：numbers = [-1,0], target = -1
 *  输出：[1,2]
 *
 * 求解思路:
 *  1. 蛮力策略
 *  2. 利用升序的特性(target-numbers[left] 越来越小): 使用left,right指针指向数组的左右侧. 在右侧找到第一个不大于 target-numbers[left]的元素, 判断是否相等, 若不等, 从left+1处继续执行. 直到找到和为target的元素.
 *  3. 二分查找: 指针index迭代数组, 对于任一index, 在index右侧使用二分查找寻找可能的和为target的另一元素.
 */

#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> ans;
    for (int i = 1, size = numbers.size(); ans.empty() && i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (numbers[i] + numbers[j] == target) {
                ans.push_back(j + 1);
                ans.push_back(i + 1);
                break;
            }
        }
    }
    return ans;
}

vector<int> twoSum2(vector<int> &numbers, int target) {
    vector<int> ans;
    for (int l = 0, r = numbers.size() - 1; ans.empty() && l < r; ++l) {
        while (target - numbers[l] < numbers[r]) r--;
        if (numbers[l] + numbers[r] == target) {
            ans.push_back(l + 1);
            ans.push_back(r + 1);
        }
    }
    return ans;
}

vector<int> twoSum3(vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
        int low = i + 1, high = numbers.size() - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (numbers[mid] == target - numbers[i]) {
                return {i + 1, mid + 1};
            } else if (numbers[mid] > target - numbers[i]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return {-1, -1};
}

#endif //ALGORITHM_TWOSUM_H
