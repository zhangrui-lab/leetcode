//
// Created by 张锐 on 2021/3/15.
//

#ifndef ALGORITHM_THECURRICULUM_H
#define ALGORITHM_THECURRICULUM_H

/*
 * 207. 课程表
 *  你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 *  在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则必须先学习课程 bi 。
 *  例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 *  请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 * eg：
 *  输入：numCourses = 2, prerequisites = [[1,0]]
 *  输出：true
 *  解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 *
 *  输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 *  输出：false
 *  解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 *
 * 1. 有向图中是否有环
 *  DFS遍历中是否存在后向边，若存在则有环
 *  BFS遍历
 *
 * 2. 拓扑排序
 *  不断移除入度为0的节点。直至不存在节点时返回true，存在节点且入度不为0时返回false;
 *
 *  // 上诉两种算法均可以不用复杂的CurriculumNode图节点实现。
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

struct CurriculumNode {
    int id;
    enum Status {
        undiscovered, visited, discovered
    };
    Status status;
    int inDegree;
    int outDegree;
    std::vector<struct CurriculumNode *> adj;

    CurriculumNode(int id) : id(id), adj(std::vector<struct CurriculumNode *>()), status(undiscovered), inDegree(0),
                             outDegree(0) {}
};

bool theCurriculumDfs(struct CurriculumNode *node) {
    node->status = CurriculumNode::discovered;
    bool ans = true;
    for (int i = 0; ans && i < node->adj.size(); i++) {
        if (node->adj[i]->status == CurriculumNode::discovered)
            return false;
        if (node->adj[i]->status == CurriculumNode::undiscovered)
            ans &= theCurriculumDfs(node->adj[i]);
    }
    node->status = CurriculumNode::visited;
    return ans;
};

bool theCurriculum(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::unordered_map<int, struct CurriculumNode *> mapping;
    for (int i = 0; i < numCourses; ++i)
        mapping[i] = new CurriculumNode(i);
    for (auto prerequisite: prerequisites)
        mapping[prerequisite[1]]->adj.push_back(mapping[prerequisite[0]]);
    bool ans = true;
    for (int i = 0; ans && i < numCourses; ++i)
        if (mapping[i]->status == CurriculumNode::undiscovered)
            ans &= theCurriculumDfs(mapping[i]);
    return ans;
}

bool theCurriculum1(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector<struct CurriculumNode *> nodes(numCourses);
    for (int i = 0; i < numCourses; ++i)
        nodes[i] = new CurriculumNode(i);
    for (auto prerequisite: prerequisites) {
        nodes[prerequisite[1]]->adj.push_back(nodes[prerequisite[0]]);
        nodes[prerequisite[0]]->inDegree++;
        nodes[prerequisite[1]]->outDegree++;
    }
    do {
        auto item = std::find_if(nodes.cbegin(), nodes.cend(), [](struct CurriculumNode *node) {
            return node->inDegree == 0;
        });
        if (item == nodes.cend())
            return false;
        for (auto adjNode: (*item)->adj)
            adjNode->inDegree--;
        nodes.erase(item);
    } while (!nodes.empty());
    return true;
}

#endif //ALGORITHM_THECURRICULUM_H
