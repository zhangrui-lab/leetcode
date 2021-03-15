//
// Created by 张锐 on 2021/3/15.
//

#ifndef ALGORITHM_SCHEDULECOURSE_H
#define ALGORITHM_SCHEDULECOURSE_H

/*
 * 630. 课程表 III
 *  这里有 n 门不同的在线课程，他们按从 1 到 n 编号。每一门课程有一定的持续上课时间（课程时间）t 以及关闭时间第 d 天。一门课要持续学习 t 天直到第 d 天时要完成，你将会从第 1 天开始。
 *  给出 n 个在线课程用 (t, d) 对表示。你的任务是找出最多可以修几门课。
 * eg:
 *  输入: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
 *  输出: 3
 *  解释:
 *      这里一共有 4 门课程, 但是你最多可以修 3 门:
 *      首先, 修第一门课时, 它要耗费 100 天，你会在第 100 天完成, 在第 101 天准备下门课。
 *      第二, 修第三门课时, 它会耗费 1000 天，所以你将在第 1100 天的时候完成它, 以及在第 1101 天开始准备下门课程。
 *      第三, 修第二门课时, 它会耗时 200 天，所以你将会在第 1300 天时完成它。
 *      第四门课现在不能修，因为你将会在第 3300 天完成它，这已经超出了关闭日期。
 * 提示:
 *  整数 1 <= d, t, n <= 10,000 。
 *  你不能同时修两门课程。
 *
 * 1. 贪心策略
 *  不断在合法候选集中选择最早结束的课程。
 */

#include <vector>
#include <queue>

int scheduleCourse(std::vector<std::vector<int>> &courses) {
    auto MyCompare = [](std::vector<int> &A, std::vector<int> &B) {
        return A[1] < B[1];
    };
    // 按照deadline从小到大排序
    sort(courses.begin(), courses.end(), MyCompare);

    // 默认就是堆头最大;
    std::priority_queue<int, std::vector<int>> myPQ;

    // 学习的天数，从第0天开始
    int day = 0;
    for (int i = 0; i < courses.size(); i++) {
        if (day + courses[i][0] <= courses[i][1]) {
            // 已经学习的天数（第几天） + 要学习课程的持续时间 小于等于 要学习课程的deadline，则直接学习掉
            myPQ.push(courses[i][0]);
            day += courses[i][0];
        } else {
            // 要学习的这门课不能直接学习了, 怎么办？
            // 1. 先放进去
            myPQ.push(courses[i][0]);
            day += courses[i][0];

            // 2. 去掉持续时间最长的课程
            int maxDuration = myPQ.top();
            day -= maxDuration;
            myPQ.pop();
        }
    }

    return myPQ.size();
}

#endif //ALGORITHM_SCHEDULECOURSE_H
