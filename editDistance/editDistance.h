//
// Created by 张锐 on 2021/1/21.
//

#ifndef ALGORITHM_EDITDISTANCE_H
#define ALGORITHM_EDITDISTANCE_H

/*
 * 72. 编辑距离
 *  给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。你可以对一个单词进行如下三种操作：
 *      1. 插入一个字符
 *      2. 删除一个字符
 *      3. 替换一个字符
 *
 * 动态规划
 *  令 dp[i][j] 为 word1[0,i), word2[0,j)的编辑距离，则原问题的解为 dp[word1.size()][word2.size()].
 *  dp[i][j] = i;                                               (j = 0)
 *           = j;                                               (i = 0)
 *           = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]-1); (word1[i-1] == word2[j-1])
 *           = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);   (word1[i-1] != word2[j-1])
 */

#include <string>
#include <vector>

int editDistance(std::string word1, std::string word2) {
    int n = word1.size(), m = word2.size();
    if (n == 0 || m == 0)
        return n + m;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= m; ++i)    // 第一行
        dp[0][i] = i;
    for (int i = 0; i <= n; ++i)    // 第一列
        dp[i][0] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = 1 + std::min(std::min(dp[i - 1][j], dp[i][j - 1]),
                                    dp[i - 1][j - 1] - (word1[i - 1] == word2[j - 1] ? 1 : 0));
        }
    }
    return dp[n][m];
}


#endif //ALGORITHM_EDITDISTANCE_H
