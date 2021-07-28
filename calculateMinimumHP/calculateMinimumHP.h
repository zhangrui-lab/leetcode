//
// Created by Administrator on 2021/7/28.
//

#ifndef ALGORITHM_CALCULATEMINIMUMHP_H
#define ALGORITHM_CALCULATEMINIMUMHP_H

/**
 * 174. 地下城游戏
 *  一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。
 *  骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
 *  有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。
 *  为了尽快到达公主，骑士决定每次只向右或向下移动一步。
 *  编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。
 *
 * 求解策略: (将二维矩阵抽象为有向图, i->j 的边上的权重为网格j中的健康点数.)
 *  1. DFS
 *  2. 带记忆优化的DFS: 对于任意房间 dungeon[i][j], 在DFS中会被达到多次, 每次都会从 dungeon[i][j] 起进行访问并尝试达到公主所在位置. 我们可以缓存从任意dungeon[i][j]到公主所在位置所需的最低生命值.
 *  3. 动态规划策略:
 *      a. dp[i][j] 表示从i,j开始能够拯救到公主所需的最低初始健康点数。
 *      b. dp[i][j] = -min(dungeon[i][j] - min(dp[i+1][j], dp[i][j+1]), 0); (i < size-1 && j < size-1)
 *                  = -min(dungeon[i][j] - dp[i+1][j], 0); (i < size-1 && j == size-1)
 *                  = -min(dungeon[i][j] - dp[i][j+1], 0); (i == size-1 && j < size-1)
 *                  = -min(dungeon[i][j], 0); (i == size-1 && j == size-1)
 */

#include <vector>
#include <utility>
#include <queue>

using namespace std;

void calculateMinimumHP(vector<vector<int>> &dungeon, pair<int, int> pos, int hp, int curMin, int &minHp) {
    curMin = min(curMin, hp);
    // 剪枝
    if (minHp <= abs(curMin) + 1)
        return;
    // 达到公主所在地
    if (pos.first == dungeon.size() - 1 && pos.second == dungeon[0].size() - 1) {
        minHp = min(abs(curMin) + 1, minHp);
    }
    // 尽可能优先向下
    if (pos.first < dungeon.size() - 1)
        calculateMinimumHP(dungeon, {pos.first + 1, pos.second}, hp + dungeon[pos.first + 1][pos.second], curMin,
                           minHp);
    // 其次向右
    if (pos.second < dungeon[0].size() - 1)
        calculateMinimumHP(dungeon, {pos.first, pos.second + 1}, hp + dungeon[pos.first][pos.second + 1], curMin,
                           minHp);
}

int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int minHp = INT_MAX;
    calculateMinimumHP(dungeon, {0, 0}, dungeon[0][0], 0, minHp);
    return minHp;
}


int calculateMinimumHP2(vector<vector<int>> &dungeon, pair<int, int> pos, vector<vector<int>> &memo) {
    if (pos.first == dungeon.size() - 1 && pos.second == dungeon[0].size() - 1)
        return -min(dungeon[pos.first][pos.second], 0);
    if (memo[pos.first][pos.second] != -1)
        return memo[pos.first][pos.second];
    int minDown =
            pos.first < dungeon.size() - 1 ? calculateMinimumHP2(dungeon, {pos.first + 1, pos.second}, memo) : INT_MAX;
    int minRight = pos.second < dungeon[0].size() - 1 ? calculateMinimumHP2(dungeon, {pos.first, pos.second + 1}, memo)
                                                      : INT_MAX;
    int minHp = -min(dungeon[pos.first][pos.second] - min(minDown, minRight), 0);
    memo[pos.first][pos.second] = minHp;
    return memo[pos.first][pos.second];
}

int calculateMinimumHP2(vector<vector<int>> &dungeon) {
    vector<vector<int>> memo(dungeon.size(), vector<int>(dungeon[0].size(), -1));
    return calculateMinimumHP2(dungeon, {0, 0}, memo) + 1;
}

int calculateMinimumHP3(vector<vector<int>> &dungeon) {
    int row = dungeon.size(), col = dungeon[0].size();
    vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
    for (int i = row - 1; i >= 0; --i) {
        for (int j = col - 1; j >= 0; --j) {
            if (i == row - 1 && j == col - 1)
                dp[i][j] = -min(dungeon[i][j], 0);
            else if (i < row - 1 && j < col - 1)
                dp[i][j] = -min(dungeon[i][j] - min(dp[i + 1][j], dp[i][j + 1]), 0);
            else if (i < row - 1)
                dp[i][j] = -min(dungeon[i][j] - dp[i + 1][j], 0);
            else
                dp[i][j] = -min(dungeon[i][j] - dp[i][j + 1], 0);
        }
    }
    return dp[0][0];
}

int calculateMinimumHP4(vector<vector<int>> &dungeon) {
    int n = dungeon.size(), m = dungeon[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[n][m - 1] = dp[n - 1][m] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int minn = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(minn - dungeon[i][j], 1);
        }
    }
    return dp[0][0] + 1;
}

#endif //ALGORITHM_CALCULATEMINIMUMHP_H
