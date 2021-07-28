//
// Created by 张锐 on 2021/3/4.
//

#ifndef ALGORITHM_LARGESTNUMBER_H
#define ALGORITHM_LARGESTNUMBER_H





/**
 * 179. 最大数
 *  给定一组非负整数 nums，重新排列它们每个数字的顺序（每个数字不可拆分）使之组成一个最大的整数。
 *  注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 *
 * 示例 1：
 *  输入：nums = [10,2]
 *  输出："210"
 *
 * 示例 2：
 *  输入：nums = [3,30,34,5,9]
 *  输出："9534330"
 *
 * 示例 3：
 *  输入：nums = [1]
 *  输出："1"
 *
 * 求解策略:
 *  1. 尽可能让较大的数占据高权重位(排在输出字符的前面).
 */

#include <string>
#include <vector>

using namespace std;

string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
        long sx = 10, sy = 10;
        while (sx <= x) {
            sx *= 10;
        }
        while (sy <= y) {
            sy *= 10;
        }
        return sy * x + y > sx * y + x;
    });
    if (nums[0] == 0) {
        return "0";
    }
    string ret;
    for (int &x : nums) {
        ret += to_string(x);
    }
    return ret;
}

#endif //ALGORITHM_LARGESTNUMBER_H
