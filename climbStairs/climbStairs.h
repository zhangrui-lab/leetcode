//
// Created by 张锐 on 2021/1/20.
//

#ifndef ALGORITHM_CLIMBSTAIRS_H
#define ALGORITHM_CLIMBSTAIRS_H

/*
 * 70. 爬楼梯
 *  假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *  注意：给定 n 是一个正整数。
 *
 * 斐波那基数列求解(动态规划求解)
 *
 * 矩阵快速幂
 */

#include <cmath>

int climbStairs1(int n) {
    if (n < 3)
        return n;
    int f1 = 1, f2 = 2, f;
    for (int i = 2; i < n; ++i) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    return f;
}

int climbStairs2(int n) {
    double sqrt5 = std::sqrt(5);
    double fibn = std::pow((1 + sqrt5) / 2, n + 1) - std::pow((1 - sqrt5) / 2, n + 1);
    return (int) std::round(fibn / sqrt5);
}


#endif //ALGORITHM_CLIMBSTAIRS_H
