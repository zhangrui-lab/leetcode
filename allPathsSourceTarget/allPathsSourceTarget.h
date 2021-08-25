//
// Created by Administrator on 2021/8/25.
//

#ifndef ALGORITHM_ALLPATHSSOURCETARGET_H
#define ALGORITHM_ALLPATHSSOURCETARGET_H

/*
 * 797. 所有可能的路径
 *  给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）
 *  二维数组的第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些节点，空就是没有下一个结点了。
 *
 * 求解策略(图可达性分析):
 *  1. DFS
 *  2. BFS: 需要记录到达当前队列中节点得所有可能路径
 */

#include <vector>
#include <queue>

using namespace std;

void allPathsSourceTarget(int node, vector<int> path, vector<vector<int>> &graph, vector<vector<int>> &ans) {
    if (node == graph.size() - 1) {
        ans.push_back(path);
        return;
    }
    for (auto iter = graph[node].cbegin(); iter != graph[node].cend(); iter++) {
        path.push_back(*iter);
        allPathsSourceTarget(*iter, path, graph, ans);
        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> ans;
    if (graph.empty()) return ans;
    allPathsSourceTarget(0, {0}, graph, ans);
    return ans;
}

#endif //ALGORITHM_ALLPATHSSOURCETARGET_H
