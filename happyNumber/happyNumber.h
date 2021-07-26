//
// Created by Administrator on 2021/7/26.
//

#ifndef ALGORITHM_HAPPYNUMBER_H
#define ALGORITHM_HAPPYNUMBER_H

/**
 * 202. 快乐数
 *  编写一个算法来判断一个数 n 是不是快乐数。
 *
 * 快乐数定义为：
 *  对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 *  如果 可以变为  1，那么这个数就是快乐数。如果 n 是快乐数就返回 true ；不是，则返回 false 。
 *
 *示例 1：
 * 输入：19
 * 输出：true
 * 解释： 1^2 + 9^2 = 82
 *       8^2 + 2^2 = 68
 *       6^2 + 8^2 = 100
 *       1^2 + 0^2 + 0^2 = 1
 *
 * 求解策略:
 *  1. 按照快乐数替换算法进行替换, 并保存替换过程中出现的中间数字. 当中间数字重复出现或者中间数字无限增大时, 意味着存在循环, 当1出现时, 终止迭代.
 *  2. 双指针法: 中间数字的维护形成了一个隐士的链式结构. 当判断链式结构中是否存在环时, 可以使用快慢指针法来判断: 当存在环时, 快慢指针必定相遇. 否则,快指针必定先到达终点.
 */

#include <set>
#include <cmath>

using namespace std;

static int getNext(int n) {
    int next = 0, mod;
    while (n) {
        mod = n % 10;
        n /= 10;
        next += mod * mod;
    }
    return next;
}

bool isHappy(int n) {
    set<int> nums;
    while (n != 1 && !nums.count(n)) {
        nums.insert(n);
        n = getNext(n);
    }
    return n == 1;
}

bool isHappy2(int n) {
    int slow = getNext(n), fast = getNext(slow);
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    return fast == 1;
}

#endif //ALGORITHM_HAPPYNUMBER_H
