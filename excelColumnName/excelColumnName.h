//
// Created by Administrator on 2021/7/23.
//

#ifndef ALGORITHM_EXCELCOLUMNNAME_H
#define ALGORITHM_EXCELCOLUMNNAME_H


/**
 * 168. Excel表列名称
 *  给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
 * 例如：
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

string excelColumnName(int columnNumber) {
    string ans;
    while (columnNumber > 0) {
        --columnNumber;
        ans += columnNumber % 26 + 'A';
        columnNumber /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

#endif //ALGORITHM_EXCELCOLUMNNAME_H
