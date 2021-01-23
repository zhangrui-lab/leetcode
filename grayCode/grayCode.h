//
// Created by 47302 on 2021/1/23.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_GRAYCODE_H
#define INTRODUCTION_TO_ALGORITHMS_GRAYCODE_H

/*
 * 89. 格雷编码
 *  格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
 *  给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种。
 *  格雷编码序列必须以 0 开头。
 *
 *  1. G(i) = i ^ (i/2);
 *  2. 由n-1的格雷编码如何获取n格雷编码。下述情况取并集
 *      1. n-1中元素全部前置加0
 *      2. n-1中元素全部前置加1
 */

#include <vector>

std::vector<int> grayCode1(int n) {
    std::vector<int> ans;
    for (int i = 0; i < 1 << n; ++i) {
        ans.push_back(i ^ i >> 1);
    }
    return ans;
}

std::vector<int> grayCode2(int n) {
    std::vector<int> ans(1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = ans.size() - 1; j >= 0; --j) {
            ans.push_back(1 << i | ans[j]);
        }
    }
    return ans;
}


#endif //INTRODUCTION_TO_ALGORITHMS_GRAYCODE_H
