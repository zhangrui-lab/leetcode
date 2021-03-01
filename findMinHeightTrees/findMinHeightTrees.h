//
// Created by 张锐 on 2021/3/1.
//

#ifndef ALGORITHM_FINDMINHEIGHTTREES_H
#define ALGORITHM_FINDMINHEIGHTTREES_H

/*
 * 310. 最小高度树
 *  树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
 *  给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。
 *  可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。
 *  请你找到所有的 最小高度树 并按任意顺序返回它们的根节点标签列表。
 *  树的高度是指根节点和叶子节点之间最长向下路径上边的数量。
 */

#include <vector>
#include <map>

std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>> &edges) {
    // todo
}

#endif //ALGORITHM_FINDMINHEIGHTTREES_H
