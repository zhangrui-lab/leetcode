//
// Created by 张锐 on 2021/1/19.
//

#ifndef ALGORITHM_INSERTINTERVAL_H
#define ALGORITHM_INSERTINTERVAL_H

/*
 * 插入区间
 *  给出一个无重叠的 ，按照区间起始端点排序的区间列表。在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 *
 * 从左至右遍历(for i=0 to n):
 *  插入位置
 *      当 intervals[i][0] >  newInterval[0] 时，当前为新区间插入位置。若i=n，插入末尾。
 *  区间合并
 *      当 intervals[i][0] > newInterval[1] || intervals[i][1] < newInterval[0]时不执行合并。
 *      当 intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[0]时不执行合并。
 *
 */

#include <vector>

std::vector<std::vector<int>> insertInterval(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval) {
    std::vector<std::vector<int>> ans;
    int nl = newInterval[0], nr = newInterval[1], inserted = 0, n = intervals.size();
    for (int i = 0; i < n; ++i) {
        if (intervals[i][1] < nl) {             // 区间i位于newInterval左侧且无交集
            ans.push_back(intervals[i]);
        } else if (intervals[i][0] > nr) {      // 区间i位于newInterval右侧且无交集
            if (!inserted) {
                inserted = 1;
                ans.push_back({nl, nr});
            }
            ans.push_back(intervals[i]);
        } else {                                // 存在交集，合并当前元素
            nl = std::min(nl, intervals[i][0]);
            nr = std::max(nr, intervals[i][1]);
        }
    }
    if (!inserted)
        ans.push_back({nl, nr});
    return ans;
}

#endif //ALGORITHM_INSERTINTERVAL_H
