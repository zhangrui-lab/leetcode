//
// Created by 张锐 on 2021/3/1.
//

#ifndef ALGORITHM_MINARRAY_H
#define ALGORITHM_MINARRAY_H

/*
 * 剑指 Offer 11. 旋转数组的最小数字
 *  把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 *  例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。
 *
 * 1. 顺序查找返回
 *  复杂度同无序序列中寻找最小元素
 * 2. 二分查找
 *  旋转数组必定局部有序:且前置有序序列最小值大于后置有序序列最大值；
 *
 *
 */

#include <vector>

int minArray(std::vector<int> &numbers) {
    int min = INT_MAX;
    for (int i = 0; i < numbers.size(); ++i)
        min = std::min(min, numbers[i]);
    return min;
}

int minArray1(std::vector<int> &numbers) {
    int lo = 0, hi = numbers.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (numbers[mid] < numbers[hi]) {
            hi = mid;
        } else if (numbers[mid] == numbers[hi]) {
            hi--;
        } else {
            lo = mid + 1;
        }
    }
    return numbers[lo];
}

#endif //ALGORITHM_MINARRAY_H
