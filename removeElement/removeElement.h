//
// Created by 张锐 on 2021/1/13.
//

#ifndef ALGORITHM_REMOVEELEMENT_H
#define ALGORITHM_REMOVEELEMENT_H

/*
 * 移除元素：给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
 *
 *
 * 双指针法
 *  指针p分割不等于和等于val的部分: nums[p] = val, nums[p+1] != val;
 *  指针i分割不等于val的部分和未探索的部分
 *
 *     不等于x    | 等于x| 未知
 *  []aaaaaaaaaaaxxxxxx.................
 *   |         p     i
 *   |
 *   前置通配符
 *
 *  每次在未知元素中找到一个等于x的元素则拓展i的范围，p不变。若在未知元素中找到一个不等于x的元素则将该元素放入p的末尾并同时拓展p，i;
 *
 *
 *  优化策略(元素的稳定性无法保持)
 *  上述策略所有不等元素均会面临一次位置的移动。指针最多移动为O(2n)次。
 *  使用p界定等于val的部分并置于末尾，指针i从头到p探索元素，遇到等于val的则放入p之后。 每次迭代中，i++ or p--. 故只需要 O(n) 次。
 *
 */

#include <vector>

int removeElement(std::vector<int> &nums, int val) {
    int p = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (val != nums[i])
            nums[++p] = nums[i];
    }
    return ++p;
}

int removeElement1(std::vector<int> &nums, int val) {
    int i = 0, p = nums.size();
    while (i < p) {
        if (nums[i] == val) {
            nums[i] = nums[--p];
        } else {
            i++;
        }
    }
    return p;
}


#endif //ALGORITHM_REMOVEELEMENT_H
