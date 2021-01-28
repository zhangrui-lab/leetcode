//
// Created by 张锐 on 2021/1/28.
//

#ifndef ALGORITHM_PASCALTRIANGLE2_H
#define ALGORITHM_PASCALTRIANGLE2_H

/*
 * 119. 杨辉三角 II
 *  给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 */

#include <vector>

std::vector<int> getRow(int rowIndex) {
    vector<int> res;
    for (int i = 0; i < rowIndex + 1; ++i) {
        vector<int> above = res;
        for (int j = 1; j < i; ++j) {
            res[j] = above[j - 1] + above[j];
        }
        res.push_back(1);
    }
    return res;
}


#endif //ALGORITHM_PASCALTRIANGLE2_H
