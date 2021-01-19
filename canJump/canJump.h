//
// Created by 张锐 on 2021/1/19.
//

#ifndef ALGORITHM_CANJUMP_H
#define ALGORITHM_CANJUMP_H

/*
 * 跳跃游戏
 *  给定一个非负整数数组，你最初位于数组的第一个位置。数组中的每个元素代表你在该位置可以跳跃的最大长度。判断你是否能够到达最后一个位置。
 *
 * 1. 迭代数组: 不断更新从起始点出发所能达到的最远位置。若最远位置大于未元素位置者可达，否则则不可达
 */

#include <vector>

bool canJump(std::vector<int> &nums) {
    if (nums.empty())
        return true;
    int farthest = nums[0];
    for (int i = 1; i < nums.size() && farthest >= i; ++i) {
        farthest = std::max(i + nums[i], farthest);
    }
    return farthest >= nums.size() - 1;
}

#endif //ALGORITHM_CANJUMP_H
