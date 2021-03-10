//
// Created by 张锐 on 2021/3/10.
//

#ifndef ALGORITHM_COUNTPRIMESETBITS_H
#define ALGORITHM_COUNTPRIMESETBITS_H

/*
 * 762. 二进制表示中质数个计算置位
 *  给定两个整数 L 和 R ，找到闭区间 [L, R] 范围内，计算置位位数为质数的整数个数。
 *  （注意，计算置位代表二进制表示中1的个数。例如 21 的二进制表示 10101 有 3 个计算置位。还有，1 不是质数。）
 */

int countPrimeSetBits(int L, int R) {
    int a[20] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
    int res = 0;
    for (int i = L; i <= R; ++i) {
        res += a[__builtin_popcount(i)];
    }
    return res;
}


#endif //ALGORITHM_COUNTPRIMESETBITS_H
