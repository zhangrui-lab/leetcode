//
// Created by 张锐 on 2021/3/15.
//

#ifndef ALGORITHM_CHECKIFPREREQUISITE_H
#define ALGORITHM_CHECKIFPREREQUISITE_H

/*
 * 1462. 课程表 IV
 *  你总共需要上 n 门课，课程编号依次为 0 到 n-1 。
 *  有的课会有直接的先修课程，比如如果想上课程 0 ，你必须先上课程 1 ，那么会以 [1,0] 数对的形式给出先修课程数对。
 *  给你课程总数 n 和一个直接先修课程数对列表 prerequisite 和一个查询对列表 queries 。
 *  对于每个查询对 queries[i] ，请判断 queries[i][0] 是否是 queries[i][1] 的先修课程。
 *  请返回一个布尔值列表，列表中每个元素依次分别对应 queries 每个查询对的判断结果。
 *  注意：如果课程 a 是课程 b 的先修课程且课程 b 是课程 c 的先修课程，那么课程 a 也是课程 c 的先修课程。
 * eg:
 *  输入：n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
 *  输出：[false,true]
 *  解释：课程 0 不是课程 1 的先修课程，但课程 1 是课程 0 的先修课程。
 *
 * 提示：
 *  2 <= n <= 100
 *  0 <= prerequisite.length <= (n * (n - 1) / 2)
 *  0 <= prerequisite[i][0], prerequisite[i][1] < n
 *  prerequisite[i][0] != prerequisite[i][1]
 *  先修课程图中没有环。
 *  先修课程图中没有重复的边。
 *  1 <= queries.length <= 10^4
 *  queries[i][0] != queries[i][1]
 *
 *
 * 1. 可达性判定
 *  在给定有向图G中,判断节点queries[i][0]是否可以到达节点queries[i][1];
 *
 * // todo
 */

#include <vector>
#include <unordered_set>


bool reachable(int src, int dst, std::vector<std::unordered_set<int>> graph) {
    if (src == dst) {
        return true;
    }
    for (const auto &neighbor : graph[src]) {
        if (reachable(neighbor, dst, graph)) {
            return true;
        }
    }
    return false;
}

std::vector<bool>
checkIfPrerequisite(int n, std::vector<std::vector<int>> &prerequisites, std::vector<std::vector<int>> &queries) {
    std::vector<std::unordered_set<int>> graph(n);
    for (const auto &pre : prerequisites) {
        graph[pre[0]].insert(pre[1]);
    }

    std::vector<bool> res;
    for (const auto &query : queries) {
        res.push_back(reachable(query[0], query[1], graph));
    }

    return res;
}

#endif //ALGORITHM_CHECKIFPREREQUISITE_H
