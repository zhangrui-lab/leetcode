//
// Created by 张锐 on 2021/3/11.
//

#ifndef ALGORITHM_PREDICTTHEWINNER_H
#define ALGORITHM_PREDICTTHEWINNER_H

/*
 * 486. 预测赢家
 *  给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。
 *  每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
 *  给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
 * eg:
 *  输入：[1, 5, 2]
 *  输出：False
 *  解释：一开始，玩家1可以从1和2中进行选择。
 *  如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）可选。
 *  所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。因此，玩家 1 永远不会成为赢家，返回 False 。
 *
 *  输入：[1, 5, 233, 7]
 *  输出：True
 *  解释：玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
 *  最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 True，表示玩家 1 可以成为赢家。
 *
 * 1. 递归
 *  为了判断哪个玩家可以获胜，需要计算一个总分，即先手得分与后手得分之差。当数组中的所有数字都被拿取时，如果总分大于或等于 0，则先手获胜，反之则后手获胜。
 *  由于每次只能从数组的任意一端拿取数字，因此可以保证数组中剩下的部分一定是连续的。
 *  计算总分时，需要记录当前玩家是先手还是后手，判断当前玩家的得分应该记为正还是负。当数组中剩下的数字多于 1 个时，当前玩家会选择最优的方案，使得自己的分数最大化，因此对两种方案分别计算当前玩家可以得到的分数，其中的最大值为当前玩家最多可以得到的分数。
 * 2. 动态规划
 *  方法一使用递归，存在大量重复计算，因此时间复杂度很高。由于存在重复子问题，因此可以使用动态规划降低时间复杂度。
 *  定义二维数组 dp，其行数和列数都等于数组的长度，dp[i][j] 表示当数组剩下的部分为下标 i 到下标 j 时，当前玩家与另一个玩家的分数之差的最大值，注意当前玩家不一定是先手。
 * 3. 极小化极大化(Minimax):
 *  1. A，B轮流进行某种决策，且决策间是相互竞争关系。假定A先进行决策。
 *  2. A，B都符合理性人假设。更确切地说，每一次决策都会选出当前最优的方案（而不会在意已经做过的决策）。
 *  1和2共同反映了极小化极大（Minimax）的定义，即此消彼长 -- 第一轮A决策极大化A自己的收益，同时间接极小化了B的收益；第二轮B则相反，如此往复；
 *  2间接确保了最优子结构的存在。仔细思考会发现这里面有一件事是重复进行的，那就是决策本身 -- 决策者只有两个可能的决策，并且他会选择让自己优势最大化的那个。
 */

#include <vector>
#include <map>
#include <utility>

int predictTheWinner(std::vector<int> &nums, int start, int end, int turn) {
    if (start == end)
        return nums[start] * turn;
    int s = nums[start] * turn + predictTheWinner(nums, start + 1, end, -turn);
    int e = nums[end] * turn + predictTheWinner(nums, start, end - 1, -turn);
    return std::max(s * turn, e * turn) * turn;
}

bool predictTheWinner(std::vector<int> &nums) {
    return predictTheWinner(nums, 0, nums.size() - 1, 1) >= 0;
}

bool predictTheWinner2(std::vector<int> &nums) {
    int length = nums.size();
    auto dp = std::vector<int>(length);
    for (int i = 0; i < length; i++)
        dp[i] = nums[i];
    for (int i = length - 2; i >= 0; i--)
        for (int j = i + 1; j < length; j++)
            dp[j] = std::max(nums[i] - dp[j], nums[j] - dp[j - 1]);
    return dp[length - 1] >= 0;
}

int predictTheWinner3(std::vector<int> &nums, int start, int end) {
    if (start == end)
        return nums[start];
    int planA = nums[start] - predictTheWinner3(nums, start + 1, end);
    int planB = nums[end] - predictTheWinner3(nums, start, end - 1);
    return std::max(planA, planB);
}

bool predictTheWinner3(std::vector<int> &nums) {
    return predictTheWinner3(nums, 0, nums.size() - 1) >= 0;
}

int predictTheWinner4(std::vector<int> &nums, int start, int end, std::map<std::pair<int, int>, int> &memo) {
    if (start == end)
        return nums[start];
    if (memo.count({start, end}))
        return memo[{start, end}];
    int planA = nums[start] - predictTheWinner3(nums, start + 1, end);
    int planB = nums[end] - predictTheWinner3(nums, start, end - 1);
    memo[{start, end}] = std::max(planA, planB);
    return memo[{start, end}];
}

bool predictTheWinner4(std::vector<int> &nums) {
    std::map<std::pair<int, int>, int> memo;
    return predictTheWinner4(nums, 0, nums.size() - 1, memo) >= 0;
}

#endif //ALGORITHM_PREDICTTHEWINNER_H
