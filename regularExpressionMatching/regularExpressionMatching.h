//
// Created by 张锐 on 2021/1/11.
//

#ifndef ALGORITHMS_REGULAREXPRESSIONMATCHING_H
#define ALGORITHMS_REGULAREXPRESSIONMATCHING_H

/*
 * 正则表达式匹配
 *
 * 蛮力策略
 * 对于任意一个*号，逐次考察其匹配源字符串0 ～ n个可能字符时，后续字符能否匹配的。
 *
 * 动态规划
 *  令f[i][j]为s[0,i]与p[0,j]的匹配情况
 *  p[j] != '*' 时:
 *      f[i][j] = f[i-1][j-1]; match(s[i], p[j])
 *              = false;
 *  p[j] = '*' 时:
 *      f[i][j] = f[i-1][j] or f[i][j-2]; match(s[i], p[j-1])
 *              = f[i][j-2];
 */

#include <vector>
#include <string>

bool isMatch(std::string s, std::string p) {
    int m = s.size();
    int n = p.size();
    auto matches = [&](int i, int j) {
        return i == 0 || p[j - 1] == '.' || s[i - 1] == p[j - 1];
    };
    std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1));
    f[0][0] = true;
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                f[i][j] |= f[i][j - 2];
                if (matches(i, j - 1)) {
                    f[i][j] |= f[i - 1][j];
                }
            } else {
                if (matches(i, j)) {
                    f[i][j] |= f[i - 1][j - 1];
                }
            }
        }
    }
    return f[m][n];
}

#endif //ALGORITHMS_REGULAREXPRESSIONMATCHING_H
