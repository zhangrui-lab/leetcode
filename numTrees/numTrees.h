//
// Created by 张锐 on 2021/1/26.
//

#ifndef ALGORITHM_NUMTREES_H
#define ALGORITHM_NUMTREES_H

/*
 * 96. 不同的二叉搜索树
 *  给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 *
 * 1. 不同的二叉搜索树的生成过程
 * 2. 动态规划策略
 */

int numTrees1(int lo, int hi) {
    if (lo > hi)
        return 1;
    int num = 0;
    for (int i = lo; i <= hi; ++i) {
        num += numTrees1(lo, i - 1) * numTrees1(i + 1, hi);
    }
    return num;
}

int numTrees1(int n) {
    if (n <= 0)
        return 0;
    return numTrees1(1, n);
}

int numTrees2(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

int numTrees3(int n) {
    long long C = 1;
    for (int i = 0; i < n; ++i) {
        C = C * 2 * (2 * i + 1) / (i + 2);
    }
    return (int) C;
}


#endif //ALGORITHM_NUMTREES_H
