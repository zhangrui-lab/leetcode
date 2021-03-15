//
// Created by 张锐 on 2021/3/15.
//

#ifndef ALGORITHM_THECURRICULUM2_H
#define ALGORITHM_THECURRICULUM2_H

/*
 * 210. 课程表 II
 *  现在你总共有 n 门课需要选，记为 0 到 n-1。
 *  在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 *  给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
 *  可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
 * eg
 *  输入: 2, [[1,0]]
 *  输出: [0,1]
 *  解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
 *
 *  输入: 4, [[1,0],[2,0],[3,1],[3,2]]
 *  输出: [0,1,2,3] or [0,2,1,3]
 *  解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
 *
 * 说明:
 *  输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
 *  你可以假定输入的先决条件中没有重复的边。
 *
 *
 *
 * 输出给定土结构的拓扑排序问题
 * 1. 基于DFS遍历算法
 *  对图结构执行DFS遍历, 记录节点的sTime,fTime等信息。返会节点访问fTime的逆序即为其拓扑排序。
 * 2. 基于入度表的算法
 *
 * // 本题参考: ../theCurriculum/theCurriculum.h
 */

#include <vector>
#include <unordered_map>
#include <unordered_set>


enum GraphNodeStatus {
    undiscovered, visited, discovered
};

bool theCurriculum21DFS(int node, int &time, std::vector<std::vector<int>> &nodes,
                        std::vector<GraphNodeStatus> &status, std::vector<int> &fTime) {
    status[node] = discovered;
    time++;
    for (auto adj: nodes[node]) {
        if (status[adj] == discovered)
            return false;
        if (status[adj] == undiscovered)
            if (!theCurriculum21DFS(adj, time, nodes, status, fTime))
                return false;
    }
    status[node] = visited;
    fTime[node] = time++;
    return true;
}

std::vector<int> theCurriculum21(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector<int> ans(numCourses);
    std::vector<GraphNodeStatus> status(numCourses);
    std::vector<int> fTime(numCourses);
    std::vector<std::vector<int>> nodes(numCourses, std::vector<int>());
    for (int i = 0; i < numCourses; ++i) {
        ans[i] = i;
        status[i] = undiscovered;
    }
    for (auto prerequisite: prerequisites)
        nodes[prerequisite[1]].push_back(prerequisite[0]);
    for (int i = 0, time = 0; i < numCourses; ++i) {
        if (status[i] == undiscovered) {
            if (!theCurriculum21DFS(i, time, nodes, status, fTime))
                return {};  // error
        }
    }
    std::sort(ans.begin(), ans.end(), [&fTime](int v1, int v2) {
        return fTime[v1] > fTime[v2];
    });
    return ans;
}

std::vector<int> theCurriculum22(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector<int> ans;
    std::unordered_set<int> selected;
    std::vector<int> inDegree(numCourses, 0);
    std::vector<std::vector<int>> nodes(numCourses, std::vector<int>());
    for (auto prerequisite: prerequisites) {
        nodes[prerequisite[1]].push_back(prerequisite[0]);
        inDegree[prerequisite[0]]++;
    }
    for (int j = 0; j < numCourses; j++) {
        int i = 0;
        for (; i < numCourses; ++i)
            if (!selected.count(i) && inDegree[i] == 0)
                break;
        if (i == numCourses)
            return {};
        for (auto adj: nodes[i])
            inDegree[adj]--;
        selected.insert(i);
        ans.push_back(i);
    }
    return ans;
}

#endif //ALGORITHM_THECURRICULUM2_H
