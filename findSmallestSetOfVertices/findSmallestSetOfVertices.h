//
// Created by 张锐 on 2021/3/18.
//

#ifndef ALGORITHM_FINDSMALLESTSETOFVERTICES_H
#define ALGORITHM_FINDSMALLESTSETOFVERTICES_H

/*
 * 1557. 可以到达所有点的最少点数目
 *  给你一个 有向无环图 ， n 个节点编号为 0 到 n-1 ，以及一个边数组 edges ，其中 edges[i] = [fromi, toi] 表示一条从点  fromi 到点 toi 的有向边。
 *  找到最小的点集使得从这些点出发能到达图中所有点。题目保证解存在且唯一。
 *  你可以以任意顺序返回这些节点编号。
 *
 * 1. 寻找途中入度为0的节点集合
 */

#include <vector>

std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>> &edges) {
    std::vector<int> inDegree(n, 0), ans;
    for (auto edge: edges)
        inDegree[edge[1]]++;
    for (int i = 0, n = inDegree.size(); i < n; ++i)
        if (inDegree[i] == 0)
            ans.push_back(i);
    return ans;
}

#endif //ALGORITHM_FINDSMALLESTSETOFVERTICES_H
