//
// Created by 张锐 on 2021/2/5.
//

#ifndef ALGORITHM_CANDY_H
#define ALGORITHM_CANDY_H

/*
 * 135. 分发糖果
 *  老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 *  你需要按照以下要求，帮助老师给这些孩子分发糖果：
 *  每个孩子至少分配到 1 个糖果。
 *  评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
 *  那么这样下来，老师至少需要准备多少颗糖果呢？
 * eg：
 *  输入：[1,0,2]
 *  输出：5
 *  解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。
 */

#include <vector>

int candy1(std::vector<int> &ratings) {
    int sum = 0, n = ratings.size(), right = 0;
    std::vector<int> left(n);
    for (int i = 0; i < n; ++i)
        left[i] = (i > 0 && ratings[i - 1] < ratings[i]) ? left[i - 1] + 1 : 1;
    for (int i = n - 1; i >= 0; --i) {
        right = (i < n - 1 && ratings[i] > ratings[i + 1]) ? right + 1 : 1;
        sum += std::max(right, left[i]);
    }
    return sum;
}

int candy2(std::vector<int> &ratings) {
    int sum = 1, inc = 1, dec = 0, pre = 1, n = ratings.size();
    for (int i = 1; i < n; ++i) {
        if (ratings[i - 1] <= ratings[i]) {
            dec = 0;
            pre = ratings[i - 1] == ratings[i] ? 1 : pre + 1;
            inc = pre;
            sum += pre;
        } else {
            dec++;
            pre = 1;
            if (dec == inc) {
                dec++;
            }
            sum += dec;
        }
    }
    return sum;
}

#endif //ALGORITHM_CANDY_H
