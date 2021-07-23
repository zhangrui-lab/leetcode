//
// Created by Administrator on 2021/7/23.
//

#ifndef ALGORITHM_EXCELTABLENUMBER_H
#define ALGORITHM_EXCELTABLENUMBER_H

/**
 * 171. Excel表列序号
 *  给定一个Excel表格中的列名称，返回其相应的列序号。
 *
 * 例如，
 *  A -> 1
 *  B -> 2
 *  C -> 3
 *  ...
 *  Z -> 26
 *  AA -> 27
 *  AB -> 28
 *  ...
 */

#include <string>

using namespace std;

int excelTableNumber(string columnTitle) {
    int num = 0;
    for (int i = 0, l = columnTitle.size(); i < l; ++i) {
        num += columnTitle[i] - 'A' + 1;
        if (i != l - 1)
            num *= 26;
    }
    return columnTitle.empty() ? 0 : num;
}

int excelTableNumber2(string columnTitle) {
    int number = 0;
    long multiple = 1;
    for (int i = columnTitle.size() - 1; i >= 0; i--) {
        int k = columnTitle[i] - 'A' + 1;
        number += k * multiple;
        multiple *= 26;
    }
    return number;
}

#endif //ALGORITHM_EXCELTABLENUMBER_H
