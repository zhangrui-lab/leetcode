//
// Created by 张锐 on 2021/1/19.
//

#ifndef ALGORITHM_MERGEINTERVALS_H
#define ALGORITHM_MERGEINTERVALS_H

/*
 * 合并区间
 *  给出一个区间的集合，请合并所有重叠的区间。
 */

#include <vector>
#include <algorithm>

std::vector<std::vector<int>> mergeIntervals1(std::vector<std::vector<int>> &intervals) {
    std::vector<std::vector<int>> ans;
    if (intervals.empty())
        return ans;
    std::sort(intervals.begin(), intervals.end());
    // 保存前一个已合并的区间
    std::vector<int> prev = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
        if (prev[1] >= intervals[i][0]) {
            prev[1] = std::max(prev[1], intervals[i][1]);
        } else {
            ans.push_back(prev);
            prev = intervals[i];
        }
    }
    ans.push_back(prev);
    return ans;
}


std::vector<std::vector<int>> mergeIntervals2(std::vector<std::vector<int>> &intervals) {
    if (intervals.size() == 0) {
        return {};
    }
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> merged;
    for (int i = 0; i < intervals.size(); ++i) {
        int L = intervals[i][0], R = intervals[i][1];
        if (!merged.size() || merged.back()[1] < L) {
            merged.push_back({L, R});
        } else {
            merged.back()[1] = std::max(merged.back()[1], R);
        }
    }
    return merged;
}

// 排序+双指针
std::vector<std::vector<int>> mergeIntervals3(std::vector<std::vector<int>> &intervals) {
    std::vector<std::vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size();) {
        int s = intervals[i][1];
        int t = i + 1;
        while (t < intervals.size() && s >= intervals[t][0]) {
            s = std::max(s, intervals[t][1]);
            t++;
        }
        ans.push_back({intervals[i][0], s});
        i = t;
    }
    return ans;
}


#endif //ALGORITHM_MERGEINTERVALS_H
