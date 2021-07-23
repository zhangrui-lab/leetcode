//
// Created by Administrator on 2021/7/23.
//

#ifndef ALGORITHM_TRAILINGZEROES_H
#define ALGORITHM_TRAILINGZEROES_H

/**
 * 172. 阶乘后的零
 *  给定一个整数 n，返回 n! 结果尾数中零的数量。
 *
 * 示例 1:
 *  输入: 3
 *  输出: 0
 *  解释: 3! = 6, 尾数中没有零。
 *
 * 示例 2:
 *  输入: 5
 *  输出: 1
 *  解释: 5! = 120, 尾数中有 1 个零.
 */

int trailingZeroes(int n) {
    //计算n/5,n/25,n/125....的结果之和即可,由于怕分母溢出，每次计算之后，先将n/5，然后再重复计算即可（因为是5的倍数）
    int ans = 0;
    while (n > 0) {
        ans += n / 5;
        n = n / 5;
    }
    return ans;
}


#endif //ALGORITHM_TRAILINGZEROES_H
