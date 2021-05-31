//
// Created by Administrator on 2021/5/31.
//

#ifndef ALGORITHM_MINCOST_H
#define ALGORITHM_MINCOST_H

/*
 * 1578. 避免重复字母的最小删除成本
 *  给你一个字符串 s 和一个整数数组 cost ，其中 cost[i] 是从 s 中删除字符 i 的代价。
 *  返回使字符串任意相邻两个字母不相同的最小删除成本。
 *  请注意，删除一个字符后，删除其他字符的成本不会改变。
 *
 * 示例 1：
 *  输入：s = "abaac", cost = [1,2,3,4,5]
 *  输出：3
 *  解释：删除字母 "a" 的成本为 3，然后得到 "abac"（字符串中相邻两个字母不相同）。
 *
 * 示例 2：
 *  输入：s = "abc", cost = [1,2,3]
 *  输出：0
 *  解释：无需删除任何字母，因为字符串中不存在相邻两个字母相同的情况。
 *
 * 示例 2：
 *  输入：s = "aabaa", cost = [1,2,3,4,1]
 *  输出：2
 *  解释：删除第一个和最后一个字母，得到字符串 ("aba") 。
 *
 * 思路:
 *  双指针界定包含重复元素的子串. 使用 p 指针指定当前重复区域内的最大成本元素位置.
 */

#include <string>
#include <vector>
#include <set>

int minCost1(std::string s, std::vector<int> &cost) {
    if (s.length() < 2)
        return 0;
    int lp = 0, rp = 1, p = lp, len = s.length(), ans = 0;
    auto compute = [&] {                // 重复区域最小成本计算算法
        for (int i = lp; i < rp; ++i) {
            if (i != p)
                ans += cost[i];
        }
    };
    for (; rp < len; ++rp) {
        if (s[lp] != s[rp]) {
            compute();
            p = lp = rp;
        } else {
            p = cost[p] >= cost[rp] ? p : rp;
        }
    }
    if (rp - lp > 2)
        compute();
    return ans;
}

int minCost2(std::string s, std::vector<int> &cost) {
    int i = 0, len = s.length(), ret = 0;
    while (i < len) {
        char ch = s[i];
        int maxValue = 0;
        int sum = 0;
        while (i < len && s[i] == ch) {
            maxValue = std::max(maxValue, cost[i]);
            sum += cost[i];
            i++;
        }
        ret += (sum - maxValue);
    }
    return ret;
}

#endif //ALGORITHM_MINCOST_H
