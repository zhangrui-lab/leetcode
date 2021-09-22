//
// Created by Administrator on 2021/9/22.
//

#ifndef ALGORITHM_KNAPSACK_PROBLEM_H
#define ALGORITHM_KNAPSACK_PROBLEM_H

#include <vector>

/**
 * 背包问题：
 *  01背包问题:
 *      dp(i, v)定义为将前i个物品入背包，可使这些物品的总体积不超过v，且总价值最大得最大价值数；dp(i, v) = max( dp(i-1, v), dp(i-1, v-V[i]) + W[i] )
 *      dp(i, v)定义为从i到N个物品入背包，可使这些物品的总体积不超过v，且总价值最大得最大价值数；dp(i, v) = max( dp(i+1, v), dp(i+1, v-V[i]) + W[i] )
 *  完全背包问题： 与01背包问题的不同之处在于完全背包可以重复选择某一物品。
 *      dp(i, v)定义为将前i个物品入背包，可使这些物品的总体积不超过v，且总价值最大得最大价值。 dp(i, v) = max( dp(i-1, v), dp(i, v-V[i]) + W[i] )
 *  多重背包问题
 *      dp(i, v)定义为将前i个物品入背包，可使这些物品的总体积不超过v，且总价值最大得最大价值数； dp(i, v) = max( dp(i, v-k*V[i]) + k*W[i]) (0<=k<=size[i] && v-k*V[i]>=0，考虑将前i个物品每个选择k次所获得的最大价值)
 *      优化：将多重背包问题转化为01背包（通过将S个物品转化为具有不同价值的x个物品（x~=logS），x的组合可以表达任意的0~S，以期降低算法的复杂度）; S个商品转化为 0 1 2 4 2^{k-1} S-2^{k}+1 个商品 (k为最高位1的位数 0 ~ i)
 *  混合背包问题
 *      对于混合背包中的任意类型商品（01，多重，完全），采用不同的基本求解策略即可。
 *  二维费用的背包问题：同一维背包同样的求解策略，只是在dp时新增一个维度。
 *      dp[i][v][m]定义为将前i个物品入背包，使这些物品的总体积不超过v，重量不超过m时的最大价值； dp[i][v][m] = max( dp[i-1][v][m], dp[i-1][v-V[i]][m-M[i]]+w[i   ] )
 *  分组背包问题：每组物品有若干个，同一组内的物品最多只能选一个。
 *      dp[i][j]定义为从前i组物品中选择最大容量为j的物品的最大价值； dp[i][j] = max( dp[i-1][j], dp[i-1][j-V[i][m]]+W[i][m] ) (v[i][m]为第i组的所有可能的物品的体积, w[i][m]为...价值)
 *  有依赖的背包问题
 *      可以考虑将具有以来关系的物品放入一个组中，对组中只能进行一次选择（组内N个物品时最高2^N种选择方式）。
 *      树型dp：dp[u][v]考虑依赖于u的物品组内的物品在不同容量v下所能获取的最大价值。 dp[u][v] = 0  (v < V[u], 被依赖节点无法放下)
 *                                                                                = max(dp[u][v], W[u] + dp[u][v-k] + dp[son][k])  (v >= V[u], son直接依赖u的物品， k为考虑为son分配任意数量容量时的情况（必须能放下u）)
 *  背包问题求方案数
 *      cnt[i][j]定义为将前i个物品入背包，可使这些物品的总体积不超过v，且总价值最大时的方案数； cnt[i][j] = cnt[i-1][j]; (dp[i][j] == dp[i-1][j])
 *                                                                                         += cnt[i-1][j-V[i]] (dp[i][j] == dp[i-1][j-V[i]])
 *  背包问题求具体方案
 *      01背包问题求具体方案 将dp(i,j)定义为从第i个元素到最后一个元素总容量为j的最优解；dp(i,j)=max(dp(i+1,j),dp(i+1,j−V[i])+W[i]) 获取具体方案时可从dp[i][j](i=1,j=v)开始判断,
 *      若dp[i][j]=dp[i+1][j-V[i]]+W[i]则i在当前方案中，并转入i=i+1,j=j-V[i]. 否则，转入i=i+1, j=j中;
 */

int main01_1() {
    int n, v, W[1001] = {0}, V[1001] = {0}, dp[1001] = {0};
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; ++i) scanf("%d %d", &V[i], &W[i]);
    for (int i = 1; i <= n; ++i) for (int j = v; j >= V[i]; --j) dp[j] = std::max(dp[j], dp[j - V[i]] + W[i]);
    printf("%d", dp[v]);
    return 0;
}

int main01_2() {
    int n, v, W[1001] = {0}, V[1001] = {0}, dp[1001] = {0};
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; ++i) scanf("%d %d", &V[i], &W[i]);
    for (int i = n; i >= 1; --i)
        for (int j = v; j >= 0; --j)
            dp[j] = std::max(dp[j], (j >= V[i] ? dp[j - V[i]] + W[i] : 0));
    printf("%d", dp[v]);
    return 0;
}

int main_full() {
    int n, v, W[1001] = {0}, V[1001] = {0}, dp[1001] = {0};
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; ++i) scanf("%d %d", &V[i], &W[i]);
    for (int i = 1; i <= n; ++i) for (int j = V[i]; j <= v; ++j) dp[j] = std::max(dp[j], dp[j - V[i]] + W[i]);
    printf("%d", dp[v]);
    return 0;
}

int main_mul_01() {
    int n, v, W[1001] = {0}, V[1001] = {0}, S[1001] = {0}, dp[1001] = {0};
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; ++i) scanf("%d %d %d", &V[i], &W[i], &S[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = v; j >= 0; --j)
            for (int k = std::min(S[i], j / V[i]); k >= 0; --k)
                dp[j] = std::max(dp[j], dp[j - k * V[i]] + k * W[i]);
    printf("%d", dp[v]);
    return 0;
}

int main_mul_02() {
    int n, v, W[1001] = {0}, V[1001] = {0}, S[1001] = {0}, dp[1001] = {0};
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; ++i) scanf("%d %d %d", &V[i], &W[i], &S[i]);
    for (int i = 1; i <= n; ++i)
        for (int k = 1, curS = std::min(S[i], v / V[i]); curS > 0; k = (k >= curS ? curS : k << 1)) {
            curS -= k;
            for (int j = v; j >= k * V[i]; --j) dp[j] = std::max(dp[j], dp[j - k * V[i]] + k * W[i]);
        }
    printf("%d", dp[v]);
    return 0;
}

int main_mix() {
    int n, v, W[1001] = {0}, V[1001] = {0}, S[1001] = {0}, dp[1001] = {0};
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; ++i) scanf("%d %d %d", &V[i], &W[i], &S[i]);
    for (int i = 1; i <= n; ++i) {
        if (S[i] == -1) {       // 01
            for (int j = v; j >= V[i]; --j) dp[j] = std::max(dp[j], dp[j - V[i]] + W[i]);
        } else if (S[i] == 0) { // 完全
            for (int j = V[i]; j <= v; ++j) dp[j] = std::max(dp[j], dp[j - V[i]] + W[i]);
        } else {                // 多重
            for (int k = 1, curS = std::min(S[i], v / V[i]); curS > 0; k = (k >= curS ? curS : k << 1)) {
                curS -= k;
                for (int j = v; j >= k * V[i]; --j) dp[j] = std::max(dp[j], dp[j - k * V[i]] + k * W[i]);
            }
        }
    }
    printf("%d", dp[v]);
    return 0;
}

int main_two() {
    int n, v, m, V[1001] = {0}, M[1001] = {0}, W[1001] = {0}, dp[1001][1001] = {0};
    scanf("%d %d %d", &n, &v, &m);
    for (int i = 1; i <= n; ++i) scanf("%d %d %d", &V[i], &M[i], &W[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = v; j >= V[i]; --j)
            for (int k = m; k >= M[i]; --k)
                dp[j][k] = std::max(dp[j][k], dp[j - V[i]][k - M[i]] + W[i]);
    printf("%d", dp[v][m]);
    return 0;
}

int main_group() {
    int n, v, S[110] = {0}, W[110][110] = {0}, V[110][110] = {0}, dp[110] = {0};
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &S[i]);
        for (int j = 1; j <= S[i]; ++j) scanf("%d %d", &V[i][j], &W[i][j]);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = v; j >= 0; --j)
            for (int k = 1; k <= S[i]; ++k) // 组内物品K必须在内层
                if (j >= V[i][k]) dp[j] = std::max(dp[j], dp[j - V[i][k]] + W[i][k]);
    printf("%d", dp[v]);
    return 0;
}

// 有依赖的背包问题

namespace Rely {
    int N, V, p, root, v[101] = {0}, w[101] = {0}, dp[101][101] = {0};
    std::vector<int> c[101];

    void dfs(int u) {
        for (int i = v[u]; i <= V; ++i) dp[u][i] = w[u];
        for (int i = 0; i < c[u].size(); ++i) {
            int son = c[u][i];
            dfs(son);
            for (int j = V; j >= v[u]; --j) {
                for (int k = 0; k <= j - v[u]; ++k) {
                    dp[u][j] = std::max(dp[u][j], dp[u][j - k] + dp[son][k]);
                }
            }
        }
    }

    int main_rely() {
        scanf("%d %d", &N, &V);
        for (int i = 1; i <= N; ++i) {
            scanf("%d %d %d", &v[i], &w[i], &p);
            if (p == -1) root = i;
            else c[p].push_back(i);
        }
        dfs(root);
        printf("%d", dp[root][V]);
        return 0;
    }
}

int main_num() {
    int n, v, W[1001] = {0}, V[1001] = {0}, dp[1001] = {0}, cnt[1001] = {1};
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; ++i) scanf("%d %d", &V[i], &W[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = v; j >= V[i]; --j) {
            int tmp = dp[j - V[i]] + W[i];
            if (tmp > dp[j]) {
                dp[j] = tmp;
                cnt[j] = cnt[j - V[i]];
            } else if (tmp == dp[j]) {
                cnt[j] = cnt[j] + cnt[j - v];
            }
        }
    printf("%d", cnt[v]);
    return 0;
}

int main_plan() {
    int v[1010], w[1010], dp[1010][1010] = {0};
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> v[i] >> w[i];
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 0; --j)
            dp[i][j] = std::max(dp[i + 1][j], j >= v[i] ? dp[i + 1][j - v[i]] + w[i] : 0);
    for (int i = 1, j = m; i <= n && j >= 0; ++i) {
        if (i == n && j >= v[i]) printf("%d", i);
        else if (j >= v[i] && dp[i][j] == dp[i + 1][j - v[i]] + w[i]) {
            j -= v[i];
            printf("%d ", i);
        }
    }
    return 0;
}

#endif //ALGORITHM_KNAPSACK_PROBLEM_H
