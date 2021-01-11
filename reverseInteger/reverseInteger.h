//
// Created by 张锐 on 2021/1/11.
//

#ifndef ALGORITHMS_REVERSEINTEGER_H
#define ALGORITHMS_REVERSEINTEGER_H

/*
 * 整数反转
 */

int reverseInteger(int x) {
    long n = 0;
    while (x) {
        n = n * 10 + x % 10;
        x /= 10;
    }
    return n > INT_MAX || n < INT_MIN ? 0 : n;
}

#endif //ALGORITHMS_REVERSEINTEGER_H
