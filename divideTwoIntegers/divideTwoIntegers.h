//
// Created by 张锐 on 2021/1/13.
//

#ifndef ALGORITHM_DIVIDETWOINTEGERS_H
#define ALGORITHM_DIVIDETWOINTEGERS_H

/*
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。返回被除数 dividend 除以除数 divisor 得到的商。
 */

int divide(int dividend, int divisor) {
    int sign;
    if ((dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0)) {
        sign = 0;
    } else {
        sign = 1;
    }
    long a = abs(dividend), cmp = abs(divisor);
    long res = 0, partial_sum = 1;
    int abs_divisor = cmp;
    if (a < cmp) return 0;
    while ((cmp << 1) < a) {
        cmp = cmp << 1;
        partial_sum = partial_sum << 1;
    }
    while (a >= abs_divisor) {
        a -= cmp;
        res += partial_sum;
        //cout << "a: " << a << " cmp: " << cmp << " partial_sum: " << partial_sum << endl;
        while (cmp > a) {
            cmp = cmp >> 1;
            partial_sum = partial_sum >> 1;
        }
    }
    if (sign == 1) {
        if (-res < INT_MIN) return INT_MAX;
        else return -res;
    } else {
        if (res > INT_MAX) return INT_MAX;
        else return res;
    }
}


#endif //ALGORITHM_DIVIDETWOINTEGERS_H
