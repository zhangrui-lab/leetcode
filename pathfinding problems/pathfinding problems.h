//
// Created by Administrator on 2021/9/23.
//

#ifndef ALGORITHM_PATHFINDING_PROBLEMS_H
#define ALGORITHM_PATHFINDING_PROBLEMS_H

/**
 * 寻路问题 给定某个可抽象为图论中的模型的图，要求找到图中满足某种性质的一条路径。除判别存在性之外，一般均要求此条路径具备某种最优性，亦即在某种计算方法下最短或最长。对于路径的起点和终点也常常有着限制。
 *
 * 1. 矩阵中的寻路: 问题是这样的：设有一 M×N 的矩阵 P，矩阵单元格中的元素皆是数字。从矩阵的左上角走到右下角，只能向右或向下走，怎样能使覆盖到的数字之和最大？ （dp时需要考虑：子问题的局部最优性是否代表着全局最优性）
 *  dfs： 考虑任意可行路径（在任意节点处均尝试向下和向右前进），并记录覆盖到的数字之和最大的路径信息。 C((M-1)/(M+N-2))
 *  dp_1，考虑第一步如何前进以其获取最大和：dp(i,j) = P(i,j)+max( dp(i+1, j), dp(i, j+1) ); (从（i，j）处达到终点的最大和必然为从(i+1, j)，(i, j+1)达到终点的较大和加上P（i，j）)
 *  dp_2，考虑最后一步如何前进以其获取最大和：dp(i,j) = P(i,j)+max( dp(i-1, j), dp(i, j-1) ); (从（0，0）处达到（i，j）的最大和必然为从（0，0）达到（i-1, j），（i, j-1）的较大和加上P（i，j）)
 *      dp_1给出自顶向下的问题求解策略，将原问题的解转化为规模较小的相同问题的解（具有重复子问题），需要使用记忆优化的递归求解策略，或使用从（M-1，N-1）处自右向左，自下网上迭代的求解策略。
 *      dp_1中求解dp(i,j)时，只用到dp(i+1, j)（下一行）, dp(i, j+1)（右边列）的数据信息。dp_2中求解dp(i,j)时，只用到dp(i-1, j)（上一行）, dp(i, j-1)（左边列）的数据信息。 故可以对dp的空间复杂度进行优化，
 *      对dp_1只保留i+1行的dp，对dp_2只保留i-1行的dp。
 *  矩阵中的寻路变形1：求积最大路径
 *  矩阵中的寻路变形2：改变路径的可行性
 *  矩阵中的寻路变形3：增加路径的条数
 *
 * 2. 从矩阵寻路到有向无环图: 仍然是 M × N 的数字矩阵 P，要求寻找的路径可以从任意一点出发，可以向上、下、左、右任意方向延伸，但路径经过的数字必须越来越小、单调递减。求矩阵中存在的最长的满足要求的路径。
 *    (“单调递减”的条件，保证了作为寻路结果的路径中不可能存在环，导致了动态规划的状态转移中不可能出现循环依赖。有向无环图的最重要性质就是，其中的定点可以进行拓扑排序。)
 *
 * 3. 单起点寻路的三种算法: 已知图 G = (V, M)，其中 V 是顶点集合，M 是表示边的邻接矩阵，求顶点 S 到其它所有顶点的最短路径。
 *  3.1. Dijkstra 算法: 用动态规划的眼光来看，需要求解的是 |V | − 1 个形式完全相同的问题，且这些问题之间明显存在着相互的关联和依赖。很容易想到，设 F[x] 为 S 到 x 的最短路径的长度这样的状态表示。
 *          状态的表示很简单，但状态之间的关系却很复杂，实际上可以是任意的。状态之间关系的复杂造成了确定求解状态顺序时的复杂。如果是有向无环图，只需要简单地按照拓扑顺序即可求解。但一般图中又按照何种顺序求
 *       解这 |V | − 1 个最短路问题呢？Edsger Dijkstra 在上世纪 50 年代提出的算法适用于顶点间边的长度均为正数的情景。在边权为正的前提下，可以根据各个状态的答案的大小来划分状态求解的顺序。例如，在
 *       算法刚刚开始的时候，在 F[1 . . . |V |] 这 |V | 个状态中，我们已知的状态只有一个：F[S] = 0，从 S 到自身的最短路径长度为零。下面根据这个状态的值去试图求解其它的状态。顶点 S 可能有若干条
 *       指向其它顶点的出边，在这些边里，肯定有最短的一条，不妨设为 M{S,S1} = k，如果我们知道了 S 到 S1 的边是 S 所有出边中最短的，我们就可以断定：F[S1] = k。原因是：边权都是正的，其它任何一条从
 *       S 迂回走向 S1 的路径，例如 S − S2 − · · · − S1 一定不会更优，因为 M{S,S1} 是同起点的边中最小的，M{S,S2} ≥ M{S,S1}。就这样，我们通过找到从起点 S 出发的长度最小的一条边的方法，将状态
 *       集合中已解出状态的数目从 1 个提高到了 2 个。我们希望能够利用类似的方法，将已解出的状态的数目不断增加，直至 S 到所有顶点的最短路径都被确定。
 *          从另一个角度来看状态集合 F，F[1 . . . |V |] 中，状态之间的相互关系是什么呢？有边 M{i,j} 相连的两个节点 i 和 j 的相互关系可以用一个不等式来刻画：F[i]+M{i,j} ≥ F[j]，其中不等式取等号当
 *       且仅当从 S 到 j 的某条最短路中，i 是 j 的前驱顶点。从这个不等式可以推出：当 F[i] 的值已解出时，可以用 F[j]<-max{F[j], F[i] + M{i,j}} 的方法来更新状态 F[j]，这也就是在最短路问题中经常用到
 *       的松弛 (relax) 操作。上面说了两方面：第一，我们可以将所有的顶点分成已解出和未解出两个集合；第二，松弛操作可以根据已解出的顶点的状态值更新未解出集合中的值。那么，在什么样的条件下，可以将一个顶点由
 *       未解出集合放入已解出集合中呢？答案是，选择未解出集合中状态值最小的那个放入已解出的集合中。这样选择的原因是，因为这个状态的值小于等于未解出集合中所有其它状态的值，在边权为正的前提下，其最短路的前驱
 *       节点必然是已解出集合中的节点，它的值不可能受任何未解出集合中状态的影响。
 *          Dijkstra 算法是按照路径的长度从小到大的顺序划分阶段、决定状态求解的顺序，但它只适用于边权为正的场合。当边权可以是负数时，在同一条最短路径中后面顶点的距离长度不一定大于前面的顶点，此时 Dijkstra 算法以及其划分阶段的方式就不再适用了。
 *  3.2. Bellman-Ford 算法
 *          在 Bellman-Ford 算法中，采用最短路径包含的边的数量从小到大的顺序划分阶段。在初始阶段时，和 Dijkstra 算法一样，只有 F[S] 是已知的，其它都设为 +∞。每个阶段中都用所有的边尝试进行松弛操作。
 *      在第一次迭代时，最短路径只包含一条边的状态肯定已经求解完毕了；尽管我们此时并不能具体地确定求解完毕的是哪些状态。在第二次迭代时，最短路径包含两条边的状态会由前阶段中求解完毕的状态加上一次松弛操作而
 *      得到。 在第 k 次迭代时，最短路径包含 k 条边的状态值会经由 k 次成功的松弛操作而被求解完毕。如果在第 k 阶段中所有的松弛操作都无效，没有更新任何一个状态的值，那么可以断定不存在包含 k 条边及以上的
 *      最短路径，可以不再继续迭代求解了。从另一个角度将，如果在第 |V| 阶段仍然有状态的值被更新，意味着存在包含边数不小于 |V| 的最短路径。然而若最短路径是不包含环的简单路的话，则包含的边数在最多（所有
 *      的定点都在这条简单路中）也只应该有 |V| − 1 条。所以，如果状态转移进行到第 |V| 阶段仍未收敛停止，则说明图中存在负环。换言之，说明图中某些顶点（从任一负环中任意顶点出发能到达的顶点）的最短路径不存在。
 *  3.3. Hamiltonian: 哈密顿回路的定义： G=(V,E)是一个图，若G中一条路径通过且仅通过每一个顶点一次，称这条路径为哈密顿路径。若G中一个回路通过且仅通过每一个顶点一次，称这个环为哈密顿回路。若一个图存在哈密顿回路，就称为哈密顿图。
 *
 */

#include <queue>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

void matrixWalkRec_dfs(int i, int j, int curr, int &max, const vector<vector<int>> &P) {
    if (i >= P.size() || j >= P.size()) return;
    if (i == P.size() - 1 && j == P[0].size() - 1) {
        max = std::max(max, curr + P[i][j]);
        return;
    }
    if (i + 1 < P.size()) matrixWalkRec_dfs(i + 1, j, curr + P[i][j], max, P);      // 尽可能向下
    if (j + 1 < P[0].size()) matrixWalkRec_dfs(i, j + 1, curr + P[i][j], max, P);   // 尽可能向右
}

int matrixWalkRec_dfs(vector<vector<int>> P) {
    assert(!P.empty() && !P[0].empty());
    int max = INT_MIN;
    matrixWalkRec_dfs(0, 0, 0, max, P);
    return max;
}

int matrixWalkRec_dp1_memo(int i, int j, vector<vector<int>> &P, vector<vector<int>> &memo) {
    if (i >= P.size() || j >= P[0].size()) return 0;
    if (memo[i][j] == INT_MIN)
        memo[i][j] = P[i][j] +
                     std::max(matrixWalkRec_dp1_memo(i + 1, j, P, memo), matrixWalkRec_dp1_memo(i, j + 1, P, memo));
    return memo[i][j];
}

int matrixWalkRec_dp1_memo(vector<vector<int>> P) {
    assert(!P.empty() && !P[0].empty());
    vector<vector<int>> memo(P.size(), vector<int>(P[0].size(), INT_MIN));
    return matrixWalkRec_dp1_memo(0, 0, P, memo);
}

int matrixWalkRec_dp1(vector<vector<int>> P) {
    assert(!P.empty() && !P[0].empty());
    int M = P.size(), N = P[0].size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = M - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
            dp[i][j] = P[i][j] + std::max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}

int matrixWalkRec_dp1_optimize(vector<vector<int>> P) {
    assert(!P.empty() && !P[0].empty());
    int M = P.size(), N = P[0].size();
    vector<int> dp(N + 1, 0);
    for (int i = M - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
            dp[j] = P[i][j] + std::max(dp[j], dp[j + 1]);
        }
    }
    return dp[0];
}

int matrixWalkRec_dp2(vector<vector<int>> P) {
    assert(!P.empty() && !P[0].empty());
    int M = P.size(), N = P[0].size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = P[i][j] + std::max((i - 1 >= 0 ? dp[i - 1][j] : 0), (j - 1 >= 0 ? dp[i][j - 1] : 0));
        }
    }
    return dp[M - 1][N - 1];
}

int matrixWalkRec_dp2_optimize(vector<vector<int>> P) {
    assert(!P.empty() && !P[0].empty());
    int M = P.size(), N = P[0].size();
    vector<int> dp(N, 0);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[j] = P[i][j] + std::max((i - 1 >= 0 ? dp[j] : 0), (j - 1 >= 0 ? dp[j - 1] : 0));
        }
    }
    return dp[N - 1];
}


// 输入为邻接矩阵：graph(n*n), 起点编号：s
vector<int> dijkstra(int s, const vector<vector<int>> &graph) {
    int n = graph.size();
    assert(s < graph.size() && n > 0 && !graph[0].empty());
    vector<int> dp(n, INT_MAX / 2);
    dp[s] = 0;
    vector<bool> solved(n, false);    // 是否已求解
    vector<int> parent(n, -1);        // parent[i]=j, 在从s到i的最短路径中，i的直接前驱节点为j；（每当存在节点j为i进行松弛时更新i的直接前驱节点）
    for (int i = 0; i < n; ++i) {           // 执行n-1次，则除s之外的n-1个节点均已求解完成
        int me = -1, tdis = INT_MAX / 2;
        for (int j = 0; j < n; ++j) {       // dp可使用priority_queue来优化以降低复杂度 O(n) -> O(logN)
            if (solved[j]) continue;
            if (dp[j] < tdis) {
                tdis = dp[j];
                me = j;
            }
        }
        if (me == -1) break;                // 未执行完成n-1次时已经不存在可达边了（非联通图）。。
        for (int k = 0; k < n; ++k) {       // 当me被加入solved时（最短路径已确定），可以对他所能到达的节点（未求解完成）进行松弛操作
            if (graph[me][k] != 0 && !solved[k] && graph[me][k] + dp[me] < dp[k]) {
                dp[k] = graph[me][k] + dp[me];
                parent[k] = me;
            }
        }
        solved[me] = true;
    }
    return dp;
}

vector<int> bellmanFord(int s, const vector<vector<int>> &graph) {
    int n = graph.size();
    assert(s < graph.size() && n > 0 && !graph[0].empty());
    vector<int> dp(n, INT_MAX / 2);
    dp[s] = 0;
    vector<int> parent(n, -1);
    for (int i = 0; i < n; ++i) {
        bool relaxation = false;
        for (int j = 0; j < n; ++j) {       // 对于任意边E(j,k)进行松弛尝试，若在第i轮能进行松弛操作，则说明图中存在大等于i的路径
            for (int k = 0; k < n; ++k) {
                if (graph[j][k] == 0) continue;
                if (graph[j][k] + dp[j] < dp[k]) {
                    relaxation = true;
                    parent[k] = j;
                    dp[k] = graph[j][k] + dp[j];
                }
            }
        }
        if (!relaxation) break;
        if (i == n - 1 && relaxation) printf("There is a negative weight cycle\n");
    }
    return dp;
}

#endif //ALGORITHM_PATHFINDING_PROBLEMS_H
