//
// Created by 张锐 on 2021/3/1.
//

#ifndef ALGORITHM_ISADDITIVENUMBER_H
#define ALGORITHM_ISADDITIVENUMBER_H

/*
 * 306. 累加数
 *  累加数是一个字符串，组成它的数字可以形成累加序列。一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。
 *  给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。
 *  说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
 *
 * DFS求解
 */

#include <string>
#include <vector>

bool isAdditiveNumber(std::string &str, long long sum, long long prev, int index, int count) {
    if (index == str.size())
        return count >= 3;
    long long val = 0;
    for (int i = index; i < str.size(); ++i) {
        if (i > index && str[index] == '0')
            break;
        val = val * 10 + str[i] - '0';
        if (count >= 2)
            if (val < sum)
                continue;
            else if (val > sum)
                break;
        if (isAdditiveNumber(str, prev + val, val, i + 1, count + 1))
            return true;
    }
    return false;
}

bool isAdditiveNumber(std::string num) {
    return isAdditiveNumber(num, 0, 0, 0, 0);
}

#endif //ALGORITHM_ISADDITIVENUMBER_H
