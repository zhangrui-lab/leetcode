//
// Created by 张锐 on 2021/3/12.
//

#ifndef ALGORITHM_SORTBYBITS_H
#define ALGORITHM_SORTBYBITS_H

/*
 * 1356. 根据数字二进制下 1 的数目排序
 *  给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
 *  如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
 *  请你返回排序后的数组。
 *
 * 1. 蛮力策略
 *  对每个十进制的数转二进制的时候统计二进制表示中的 11 的个数即可。
 *
 * 2. 把 n 往右移 32 次，每次都和 1 进行与运算
 *
 * 3. 每次消去最右边的 1，直到消完为止
 *        n: ....01010...01000
 *      n-1: ....01010...00111
 *  n&(n-1): ....01010...00000 // 消去最后一个1
 */

// https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits/solution/wei-yun-suan-he-pai-xu-kan-wan-ni-neng-xie-chu-sha/

#include <vector>

std::vector<int> sortByBits(std::vector<int> &arr) {
    auto count = [](int num) {
        int n = 0;
        while (num > 0) {
            n += num & 1;
            num >>= 1;
        }
        return n;
    };
    auto compare = [&count](int num1, int num2) {
        int c1 = count(num1), c2 = count(num2);
        return c1 < c2 ? true : (c1 > c2 ? false : num1 <= num2);
    };
    std::sort(arr.begin(), arr.end(), compare);
    return arr;
}

int hammingWeight2(int n) {
    int cnt = 0;
    for (int i = 0; i < 32; ++i) {
        cnt += (n >> i) & 1;
    }
    return cnt;
}

int hammingWeight3(int n) {
    int cnt = 0;
    while (n) {
        n &= n - 1;
        cnt++;
    }
    return cnt;
}

#endif //ALGORITHM_SORTBYBITS_H
