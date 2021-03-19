//
// Created by 张锐 on 2021/3/19.
//

#ifndef ALGORITHM_LONGESTWPI_H
#define ALGORITHM_LONGESTWPI_H

/*
 * 1124. 表现良好的最长时间段
 *  给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。
 *  我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。
 *  所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格大于「不劳累的天数」。
 *  请你返回「表现良好时间段」的最大长度。
 * eg:
 *  输入：hours = [9,9,6,0,6,6,9]
 *  输出：3
 *  解释：最长的表现良好时间段是 [9,9,6]。
 *
 * 和大于0得最大连续子数组问题: 将每天转化为 1(劳累的一天)/-1(不劳累的天数)。 获取和大于0得最大连续子数组
 *
 * 1. 暴力求解 // todo
 *
 *
 */

#include <vector>

//   1 1 -1 -1 -1 -1 1
// 0 1 2  1 0 -1 -2 -1

int longestWPI(std::vector<int> &hours) {
    int n = hours.size();
    std::vector<int> pSum(n, 0);
    for (int i = 0; i < n; ++i)
        pSum[i] = i == 0 ? hours[i] : pSum[i] + hours[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
        }
    }
}


#endif //ALGORITHM_LONGESTWPI_H
