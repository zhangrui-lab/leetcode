//
// Created by 张锐 on 2021/1/19.
//

#ifndef ALGORITHM_PERMUTATIONSEQUENCE_H
#define ALGORITHM_PERMUTATIONSEQUENCE_H

/*
 * 排列序列
 *  给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。按大小顺序列出所有排列情况，给定 n 和 k，返回第 k 个排列。
 *
 *
 * [1,2...i]的排列总数为i!;
 *  最高位为1的排列总数为(i-1)!
 *  最高位为2的排列总数为(i-1)!
 *      :           :
 *      :           :
 *      :           :
 *  最高位为i的排列总数为(i-1)!
 *      故长度为i的第k个阶乘的最高位为第 k-1/(i-1)! + 1 大的数
 *      故长度为i的第k个阶乘的第二高位为第 (k-1)%(i-1)!/(i-2)! + 1 大的数
 *          :   :
 *          :   :
 *      当 k=1 时，剩余元素顺序排列。
 *
 * 深度优先遍历 + 剪枝
 *  在递归第i层我们作出选择时, 知道当前选址之后存在 (i-1)! 排列。可以根据当前选择的可能列和k值作出剪枝。
 */

#include <string>
#include <unordered_set>

std::string getPermutation1(int n, int k) {
    std::vector<char> chs = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    const int factor[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    std::string str;
    for (--k; n--; k %= factor[n]) {
        const int i = k / factor[n];
        str.push_back(chs[i]);
        chs.erase(chs.begin() + i);
    }
    return str;
}

std::string getPermutation2(int n, int k) {
    std::vector<int> fact(n);
    fact[0] = 1;
    for (int i = 1; i < n; ++i)
        fact[i] = fact[i - 1] * i;
    --k;
    std::string ans;
    std::vector<int> valid(n + 1, 1);
    // i: 当前已确认多少位。 j: 寻找第i为的值
    for (int i = 1; i <= n; ++i) {
        int order = k / fact[n - i] + 1;
        for (int j = 1; j <= n; ++j) {
            order -= valid[j];
            if (!order) {
                ans += (j + '0');
                valid[j] = 0;
                break;
            }
        }
        k %= fact[n - i];
    }
    return ans;
}

// index 在这一步之前已经选择了几个数字，其值恰好等于这一步需要确定的下标位置
void getPermutation3(int n, int index, int k, std::vector<int> &fact, std::vector<bool> &used, std::string &curr) {
    if (n == index)
        return;
    int cnt = fact[n - index - 1];
    for (int i = 1; i <= n; ++i) {
        if (used[i])
            continue;
        if (cnt < k) {
            k -= cnt;
            continue;
        }
        used[i] = true;
        curr += (i + '0');
        getPermutation3(n, index + 1, k, fact, used, curr);
        return;
    }
}

std::string getPermutation3(int n, int k) {
    std::vector<int> fact(n);
    fact[0] = 1;
    for (int i = 1; i < n; ++i)
        fact[i] = fact[i - 1] * i;
    std::string ans;
    std::vector<bool> used(n + 1, false);
    getPermutation3(n, 0, k, fact, used, ans);
    return ans;
}

#endif //ALGORITHM_PERMUTATIONSEQUENCE_H
