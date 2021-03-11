//
// Created by 张锐 on 2021/3/11.
//

#ifndef ALGORITHM_ISMONOTONIC_H
#define ALGORITHM_ISMONOTONIC_H

/*
 * 896. 单调数列
 *  如果数组是单调递增或单调递减的，那么它是单调的。
 *  如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。
 *  当给定的数组 A 是单调数组时返回 true，否则返回 false。
 * eg:
 *  输入：[1,2,2,3]
 *  输出：true
 *
 *  输入：[6,5,4,4]
 *  输出：true
 */

bool isMonotonic(std::vector<int> &A) {
    bool incr = 1, decr = 1;
    for (int i = 1, n = A.size(); i < n; ++i) {
        incr &= A[i] >= A[i - 1];
        decr &= A[i] <= A[i - 1];
    }
    return incr | decr;
}

#endif //ALGORITHM_ISMONOTONIC_H