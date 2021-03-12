//
// Created by 张锐 on 2021/3/12.
//

#ifndef ALGORITHM_SHUFFLEARRAY_H
#define ALGORITHM_SHUFFLEARRAY_H

/*
 * 384. 打乱数组
 *  给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。
 * 实现 Solution class:
 *  Solution(int[] nums) 使用整数数组 nums 初始化对象
 *  int[] reset() 重设数组到它的初始状态并返回
 *  int[] shuffle() 返回数组随机打乱后的结
 *
 *
 * elem=[e1 e2 e3 e4 e5 e6]; lo=0,hi=elem.size;
 * 区间置乱策略:
 *  for i=elem.size to 1:
 *      std::swap(elem[rand() % i], elem[i-1]);
 *
 * 1.：Fisher-Yates 洗牌算法 (就是上诉区间置乱策略)
 * 思路
 *  我们可以用一个简单的技巧来降低之前算法的时间复杂度和空间复杂度，那就是让数组中的元素互相交换，这样就可以避免掉每次迭代中用于修改列表的时间了。
 * 算法
 *  Fisher-Yates 洗牌算法跟暴力算法很像。在每次迭代中，生成一个范围在当前下标到数组末尾元素下标之间的随机整数。接下来，将当前元素和随机选出的下标所指的元素互相交换 - 这一步模拟了每次从 “帽子”
 *  里面摸一个元素的过程，其中选取下标范围的依据在于每个被摸出的元素都不可能再被摸出来了。此外还有一个需要注意的细节，当前元素是可以和它本身互相交换的 - 否则生成最后的排列组合的概率就不对了。
 */

#include <vector>

class ShuffleArray {
public:
    ShuffleArray(std::vector<int> &nums) : nums(nums) {
    }

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() {
        std::vector<int> tmp(nums);
        for (int i = tmp.size(); i > 0; --i)
            std::swap(tmp[rand() % i], tmp[i-1]);
        return tmp;
    }

private:
    std::vector<int> nums;
};

#endif //ALGORITHM_SHUFFLEARRAY_H
