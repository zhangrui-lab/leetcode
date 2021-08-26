//
// Created by Administrator on 2021/8/26.
//

#ifndef ALGORITHM_ROB3_H
#define ALGORITHM_ROB3_H

/**
 * 337. 打家劫舍 III
 *  在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有
 *  一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
 *  计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
 *
 * 求解策略:
 *  1. DFS: O(2^n)
 *  2. 记忆优化dfs
 *  3. 动态规划
 *  4. 优化动态规划的空间复杂度
 */

#include "../common.h"
#include <algorithm>
#include <unordered_map>

using namespace std;

int rob(TreeNode *root, bool can = true) {
    int val = 0;
    if (!root) return val;
    if (can) {
        val = max(root->val + rob(root->left, false) + rob(root->right, false),
                  rob(root->left, true) + rob(root->right, true));
    } else {
        val = rob(root->left, true) + rob(root->right, true);
    }
    return val;
}

int dfs(TreeNode *root, int can, unordered_map<TreeNode *, vector<int>> &memo) {
    if (memo.find(root) != memo.end() && memo[root][can] != -1)
        return memo[root][can];
    memo[root] = {-1, -1};
    if (can) {
        memo[root][can] = max(root->val + dfs(root->left, 0, memo) + dfs(root->right, 0, memo),
                              dfs(root->left, 1, memo) + dfs(root->right, 1, memo));
    } else {
        memo[root][can] = dfs(root->left, 1, memo) + dfs(root->right, 1, memo);
    }
    return memo[root][can];
}

int rob2(TreeNode *root) {
    unordered_map<TreeNode *, vector<int>> memo;
    memo[nullptr] = {0, 0};
    return dfs(root, true, memo);
}

void dfs(TreeNode *root, unordered_map<TreeNode *, int> &selected, unordered_map<TreeNode *, int> &unselected) {
    if (!root) return;
    dfs(root->left, selected, unselected);
    dfs(root->right, selected, unselected);
    selected[root] = root->val + unselected[root->left] + unselected[root->right];
    unselected[root] =
            max(selected[root->left], unselected[root->left]) + max(selected[root->right], unselected[root->right]);
}

int rob3(TreeNode *root) {
    unordered_map<TreeNode *, int> selected, unselected;
    dfs(root, selected, unselected);
    return max(selected[root], unselected[root]);
}

pair<int, int> dfs(TreeNode *root) {    // {unselected, selected}
    if (!root) return {0, 0};
    pair<int, int> lv = dfs(root->left), rv = dfs(root->right);
    return {max(lv.first, lv.second) + max(rv.first, rv.second), root->val + lv.first + rv.first};
}

int rob4(TreeNode *root) {
    pair<int, int> vals = dfs(root);
    return max(vals.first, vals.second);
}

#endif //ALGORITHM_ROB3_H
