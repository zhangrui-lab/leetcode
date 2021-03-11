//
// Created by 张锐 on 2021/3/11.
//

#ifndef ALGORITHM_SLIDINGPUZZLE_H
#define ALGORITHM_SLIDINGPUZZLE_H

/*
 * 773. 滑动谜题
 *  在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.
 *  一次移动定义为选择 0 与一个相邻的数字（上下左右）进行交换.
 *  最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。
 *  给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。
 * eg:
 *  输入：board = [[1,2,3],[4,0,5]]
 *  输出：1
 *  解释：交换 0 和 5 ，1 步完成
 *
 *  输入：board = [[1,2,3],[5,4,0]]
 *  输出：-1
 *  解释：没有办法完成谜板
 *
 * 1. BFS求解策略
 *  可以把这道题看成一个找出图中最短路径的问题。每个节点都是棋盘的一个状态，如果两个状态之间可以通过一步操作来完成转换，就用一条边将这两个节点相连。用广度优先搜索来解决最短路径问题。
 *  可将0视作为当前图中正在被访问的节点。0的上下左右为当前位置的邻接节点。
 *  [0 1 2]
 *  [3 4 5]
 */

#include <queue>
#include <string>
#include <vector>
#include <unordered_set>

int slidingPuzzle(std::vector<std::vector<int>> &board) {
    // 初始化操作
    std::vector<std::vector<int>> adjacentNodes = {
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {3, 1, 5},
            {4, 2},
    };
    std::queue<std::string> q;
    std::unordered_set<std::string> visited;
    std::string end = "123450", start = "";
    for (auto item: board)
        for (int i = 0; i < 3; ++i)
            start.push_back(item[i] + '0');
    q.push(start);
    visited.insert(start);
    // BFS START
    int step = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            std::string s = q.front();
            if (s == end)
                return step;
            q.pop();
            int index = 0;
            for (; s[index] != '0'; index++);
            for (auto adjacent: adjacentNodes[index]) {
                std::string t = s;
                std::swap(t[adjacent], t[index]);
                if (visited.count(t))
                    continue;
                q.push(t);
                visited.insert(t);
            }
        }
        step++;
    }
    // BFS END
    return -1;
}


#endif //ALGORITHM_SLIDINGPUZZLE_H



