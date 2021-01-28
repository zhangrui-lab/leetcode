//
// Created by 张锐 on 2021/1/28.
//

#ifndef ALGORITHM_PASCALTRIANGLE_H
#define ALGORITHM_PASCALTRIANGLE_H

/*
 * 118. 杨辉三角
 *  给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 *
 * 1. 蛮力
 * 2. 数学计算
 */

#include <vector>

std::vector<std::vector<int>> pascalTriangle(int numRows) {
    if (numRows == 0)
        return {};
    if (numRows == 1)
        return {{1}};
    std::vector<std::vector<int>> ans;
    ans.push_back({1});
    ans.push_back({1, 1});
    if (numRows == 2)
        return ans;
    std::vector<int> prev(2, 1);
    for (int i = 2; i < numRows; ++i) {
        std::vector<int> curr;
        curr.push_back(prev[0]);
        for (int j = 1; j < prev.size(); ++j) {
            curr.push_back(prev[j - 1] + prev[j]);
            if (j == prev.size() - 1)
                curr.push_back(prev[j]);
        }
        ans.push_back(curr);
        prev = curr;
    }
    return ans;
}

std::vector<std::vector<int>> pascalTriangle2(int numRows) {
    std::vector<std::vector<int>> ret(numRows);
    for (int i = 0; i < numRows; ++i) {
        ret[i].resize(i + 1);
        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
    }
    return ret;
}


#endif //ALGORITHM_PASCALTRIANGLE_H
