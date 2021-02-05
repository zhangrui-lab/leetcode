//
// Created by 张锐 on 2021/2/5.
//

#ifndef ALGORITHM_SINGLENUMBER2_H
#define ALGORITHM_SINGLENUMBER2_H

/*
 * 137. 只出现一次的数字 II
 *  给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
 * 说明：
 *  你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 示例 1:
 *  输入: [2,2,3,2]
 *  输出: 3
 */

#include <vector>

int singleNumber21(std::vector<int> &nums) {
    int once = 0, twice = 0;
    for (auto x : nums) {
        once = (once ^ x) & (~twice);
        twice = (twice ^ x) & (~once);
    }
    return once;
}


#endif //ALGORITHM_SINGLENUMBER2_H
