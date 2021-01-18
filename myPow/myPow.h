//
// Created by 张锐 on 2021/1/18.
//

#ifndef ALGORITHM_MYPOW_H
#define ALGORITHM_MYPOW_H

/*
 * Pow(x, n)
 *  实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 *
 * 平方求值法
 * 二进制分析将平方求值法转化为迭代形式
 * x^y; (y: 10101 => 2^0+2^2+2^4)
 *  x^(2^0+2^2+2^4) = x^(2^0)*x^(2^2)*x^(2^4)
 */

double myPow(double x, int n) {
    long N = n;
    if (n < 0) {
        N = -n;
        x = 1 / x;
    }
    double ans = 1;
    for (long i = 0; i < N; ++i) {
        ans *= x;
    }
    return ans;
}

double quickMul1(double x, long long N) {
    if (N == 0) {
        return 1.0;
    }
    double y = quickMul1(x, N / 2);
    return N % 2 == 0 ? y * y : y * y * x;
}

double myPow1(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul1(x, N) : 1.0 / quickMul1(x, -N);
}

double myPow2(double x, int n) {
    long long N = std::abs(n);
    int sym = n >=0 ? 1 : 0;
    double ans = 1.0;
    double weight = x;
    while (N > 0) {
        if (N % 2 == 1) {
            ans *= weight;
        }
        weight *= weight;
        N /= 2;
    }
    return sym ? ans : 1.0 / ans;
}


#endif //ALGORITHM_MYPOW_H
