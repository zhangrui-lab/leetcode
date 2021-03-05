//
// Created by 张锐 on 2021/3/5.
//

#ifndef ALGORITHM_COUNTMATCHES_H
#define ALGORITHM_COUNTMATCHES_H

/*
 * 1773. 统计匹配检索规则的物品数量
 *  给你一个数组 items ，其中 items[i] = [typei, colori, namei] ，描述第 i 件物品的类型、颜色以及名称。
 *  另给你一条由两个字符串 ruleKey 和 ruleValue 表示的检索规则。
 *  如果第 i 件物品能满足下述条件之一，则认为该物品与给定的检索规则 匹配 ：
 *  ruleKey == "type" 且 ruleValue == typei 。
 *  ruleKey == "color" 且 ruleValue == colori 。
 *  ruleKey == "name" 且 ruleValue == namei 。
 *  统计并返回 匹配检索规则的物品数量 。
 */

#include <vector>
#include <string>
#include <unordered_map>

int countMatches(std::vector<std::vector<std::string>> &items, std::string ruleKey, std::string ruleValue) {
    std::unordered_map<std::string, int> mappings = {
            {"type",  0},
            {"color", 1},
            {"name",  2},
    };
    int matched = 0;
    for (auto item: items)
        matched += (int) (ruleValue == item[mappings[ruleKey]]);
    return matched;
}

#endif //ALGORITHM_COUNTMATCHES_H
