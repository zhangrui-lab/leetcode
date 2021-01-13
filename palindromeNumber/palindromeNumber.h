//
// Created by 张锐 on 2021/1/11.
//

#ifndef ALGORITHMS_PALINDROMENUMBER_H
#define ALGORITHMS_PALINDROMENUMBER_H

/*
 * 回文数
 */

bool isPalindrome(int x) {
    if (x < 0 || x > 0 && (x % 10 == 0))
        return false;
    long rev = 0;
    int o = x;
    while (o) {
        rev = rev * 10 + o % 10;
        o /= 10;
    }
    return rev < INT_MAX && rev > INT_MIN && rev == x;
}

//翻转一半的整数
bool isPalindrome1(int x) {
    if (x < 0 || x > 0 && (x % 10 == 0))
        return false;
    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
    return x == revertedNumber || x == revertedNumber / 10;
}

#endif //ALGORITHMS_PALINDROMENUMBER_H
