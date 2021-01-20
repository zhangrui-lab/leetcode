//
// Created by 张锐 on 2021/1/20.
//

#ifndef ALGORITHM_MYSQRT_H
#define ALGORITHM_MYSQRT_H

/*
 * 69. x 的平方根
 *  实现 int sqrt(int x) 函数。计算并返回 x 的平方根，其中 x 是非负整数。由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 */

int mySqrt(int x) {
    int l = 0, r = x, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long long) mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

#endif //ALGORITHM_MYSQRT_H
