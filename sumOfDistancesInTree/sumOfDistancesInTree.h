//
// Created by Administrator on 2021/8/31.
//

#ifndef ALGORITHM_SUMOFDISTANCESINTREE_H
#define ALGORITHM_SUMOFDISTANCESINTREE_H

/**
 * 834. 树中距离之和
 *  给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1 条边 。第 i 条边连接节点 edges[i][0] 和 edges[i][1] 。
 *  返回一个表示节点 i 与其他所有节点距离之和的列表 ans。
 *
 * 求解策略:
 *  1. 蛮力bfs
 *  2. 蛮力dfs
 *  3. 蛮力优化: 动态规划
 *      dp(x) 返回以x为根的子树中节点到x的距离和.
 *      size(x) 返回以x为根的子树中的节点数目.
 *      dp[u] = for_each(v: u.child): dp[v]+size[v]     (size[v]表示所有子节点到达v之后额外达到u的距离, size[v] * 1)
 * 4. 动态规划优化:
 *      通过dp[u]用O(1)的时间求dp[v](v为u的子节点).
 *      dp[u] -> dp[v] 表示树原本已u为根, 现已v为很. 再转换中, 除了 dp[u], size[u], dp[v], size[v] 其他节点皆无变化
 *      dp[u]   -= dp[v]+size[v]
 *      size[u] -= size[v]
 *      dp[v]   += dp[u]+size[u]
 *      size[v] += size[u]
 */

#include <queue>
#include <vector>
#include <numeric>
#include "../common.h"
#include <unordered_set>

using namespace std;

vector<vector<int>> getReachable(int n, vector<vector<int>> &edges) {
    vector<vector<int>> reachable(n);
    for (auto iter = edges.cbegin(); iter != edges.cend(); iter++) {
        reachable[iter->front()].push_back(iter->back());
        reachable[iter->back()].push_back(iter->front());
    }
    return reachable;
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    vector<vector<int>> reachable = getReachable(n, edges);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int dis = 0, node;
        unordered_set<int> visited;
        queue<int> unvisited({i});
        // bfs
        while (!unvisited.empty()) {
            int size = unvisited.size();
            while (size--) {
                node = unvisited.front();
                unvisited.pop();
                visited.insert(node);
                for (auto iter = reachable[node].cbegin(); iter != reachable[node].cend(); iter++)
                    if (!visited.count(*iter)) unvisited.push(*iter);
                ans[i] += dis;
            }
            dis++;
        }
    }
    return ans;
}

int dfs(int node, int depth, vector<vector<int>> &reachable, unordered_set<int> &visited) {
    if (visited.count(node)) return 0;
    int sum = depth;
    visited.insert(node);
    for (auto iter = reachable[node].cbegin(); iter != reachable[node].cend(); iter++)
        if (!visited.count(*iter)) sum += dfs(*iter, depth + 1, reachable, visited);
    return sum;
}

vector<int> sumOfDistancesInTree2(int n, vector<vector<int>> &edges) {
    vector<int> ans(n);
    vector<vector<int>> reachable = getReachable(n, edges);
    for (int i = 0; i < n; ++i) {
        unordered_set<int> visited;
        ans[i] = dfs(i, 0, reachable, visited);
    }
    return ans;
}

void dfs(int n, int p, vector<vector<int>> &reachable, vector<int> &size, vector<int> &dp) {
    dp[n] = 0;
    size[n] = 1;
    for (auto iter = reachable[n].cbegin(); iter != reachable[n].cend(); iter++) {
        if (*iter == p) continue;
        dfs(*iter, n, reachable, size, dp);
        dp[n] += dp[*iter] + size[*iter];
        size[n] += size[*iter];
    }
}

vector<int> sumOfDistancesInTree3(int n, vector<vector<int>> &edges) {
    vector<int> ans, size, dp;
    vector<vector<int>> reachable = getReachable(n, edges);
    for (int i = 0; i < n; ++i) {
        dfs(i, -1, reachable, size, dp);
        ans[i] = dp[i];
    }
    return ans;
}

void dfs2(int u, int p, vector<int> &size, vector<int> &dp, vector<int> &ans, vector<vector<int>> &reachable) {
    ans[u] = dp[u];
    for (auto iter = reachable[u].cbegin(); iter != reachable[u].cend(); iter++) {
        int v = *iter;
        if (v == p) continue;
        int du = dp[u], su = size[u];
        int dv = dp[v], sv = size[v];

        dp[u] -= dp[v] + size[v], size[u] -= size[v];
        dp[v] += dp[u] + size[u], size[v] += size[u];

        dfs2(v, u, size, dp, ans, reachable);
        dp[u] = du;
        dp[v] = dv;
        size[u] = su;
        size[v] = sv;
    }
}

vector<int> sumOfDistancesInTree4(int n, vector<vector<int>> &edges) {
    vector<int> ans, size, dp;
    vector<vector<int>> reachable = getReachable(n, edges);
    dfs(0, -1, reachable, size, dp);
    dfs2(0, -1, size, dp, ans, reachable);
    return ans;
}

#endif //ALGORITHM_SUMOFDISTANCESINTREE_H
