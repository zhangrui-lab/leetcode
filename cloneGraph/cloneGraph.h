//
// Created by 张锐 on 2021/2/5.
//

#ifndef ALGORITHM_cloneGraph1_H
#define ALGORITHM_cloneGraph1_H

/*
 * 133. 克隆图
 *  给你无向连通图中一个节点的引用，请你返回该图的深拷贝（克隆）。
 *  图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
 *
 * 1. DFS
 * 2. BFS
 */

#include "../common.h"
#include <unordered_map>
#include <queue>

GNode *cloneGraph1(GNode *node, std::unordered_map<GNode *, GNode *> &cloned) {
    if (!node)
        return node;
    if (cloned.find(node) != cloned.end())
        return cloned[node];
    GNode *newNode = new GNode(node->val);
    cloned[node] = newNode;
    for (int i = 0; i < node->neighbors.size(); ++i) {
        newNode->neighbors.push_back(cloneGraph1(node->neighbors[i], cloned));
    }
    return newNode;
}

GNode *cloneGraph1(GNode *node) {
    std::unordered_map<GNode *, GNode *> cloned;
    return cloneGraph1(node, cloned);
}


GNode *cloneGraph2(GNode *node) {
    if (!node)
        return node;
    std::queue<GNode *> queue;
    std::unordered_map<GNode *, GNode *> cloned;
    queue.push(node);
    cloned[node] = new GNode(node->val);
    while (!queue.empty()) {
        auto tmp = queue.front();
        queue.pop();
        for (auto &neighbor : tmp->neighbors) {
            if (cloned.find(neighbor) != cloned.end()) {
                cloned[neighbor] = new GNode(neighbor->val);
                queue.push(neighbor);
            }
            cloned[tmp]->neighbors.emplace_back(cloned[neighbor]);
        }
    }
    return cloned[node];
}

#endif //ALGORITHM_cloneGraph1_H
