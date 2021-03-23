//
// Created by 张锐 on 2021/3/23.
//

#ifndef ALGORITHM_POWERFULINTEGERS_H
#define ALGORITHM_POWERFULINTEGERS_H

/*
 * 970. 强整数
 *  给定两个正整数 x 和 y，如果某一整数等于 x^i + y^j，其中整数 i >= 0 且 j >= 0，那么我们认为该整数是一个强整数。
 *  返回值小于或等于 bound 的所有强整数组成的列表。
 *  你可以按任何顺序返回答案。在你的回答中，每个值最多出现一次。
 *
 * 提示：
 *  1 <= x <= 100
 *  1 <= y <= 100
 *  0 <= bound <= 10^6
 *
 * 1. DFS求解所有可能的i,j
 * 2. 迭代考察所有可能的i，j
 */

#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

void powerfulIntegers(int x, int y, int i, int j, int bound, std::set<int> &ans) {
    int t = std::pow(x, i) + std::pow(y, j);
    if (t > bound)
        return;
    ans.insert(t);
    if (x != 1)
        powerfulIntegers(x, y, i + 1, j, bound, ans);
    if (y != 1)
        powerfulIntegers(x, y, i, j + 1, bound, ans);
}

std::vector<int> powerfulIntegers(int x, int y, int bound) {
    std::set<int> ans;
    powerfulIntegers(x, y, 0, 0, bound, ans);
    return std::vector<int>(ans.cbegin(), ans.cend());
}

std::vector<int> powerfulIntegers2(int x, int y, int bound) {
    std::set<int> seen;
    for (int i = 0; i < 18 && std::pow(x, i) <= bound; ++i)
        for (int j = 0; j < 18 && std::pow(y, j) <= bound; ++j) {
            int v = (int) std::pow(x, i) + (int) std::pow(y, j);
            if (v <= bound)
                seen.insert(v);
        }
    return std::vector<int>(seen.cbegin(), seen.cend());
}

#endif //ALGORITHM_POWERFULINTEGERS_H
