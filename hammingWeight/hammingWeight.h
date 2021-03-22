//
// Created by 张锐 on 2021/3/22.
//

#ifndef ALGORITHM_HAMMINGWEIGHT_H
#define ALGORITHM_HAMMINGWEIGHT_H

/*
 * 191. 位1的个数
 *  编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
 * 提示：
 *  请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
 */


int hammingWeight(uint32_t n) {
    int c = 0;
    while (n) {
        c += n & 1;
        n >>= 1;
    }
    return c;
}

int hammingWeight2(uint32_t n) {
    int c = 0;
    for (int i = 0; i < 32; ++i)
        if (n & (1 << i))
            c++;
    return c;
}

int hammingWeight3(uint32_t n) {
    int c = 0;
    while (n) {
        c++;
        n &= n - 1;
    }
    return c;
}

int hammingWeight4(uint32_t n) {
    int ans = 0;
    while (n) {
        ans += n % 2;
        n >>= 1;
    }
    return ans;
}

int hammingWeight5(uint32_t n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}

#endif //ALGORITHM_HAMMINGWEIGHT_H
