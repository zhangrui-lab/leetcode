//
// Created by 张锐 on 2021/3/23.
//

#ifndef ALGORITHM_NESTEDITERATOR_H
#define ALGORITHM_NESTEDITERATOR_H

#include "../common.h"
#include <vector>
#include <stack>

/*
 * 341. 扁平化嵌套列表迭代器
 *  给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
 *  列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。
 */

class NestedIterator {
private:
    std::vector<int> vals;
    std::vector<int>::iterator cur;

    void dfs(const std::vector<NestedInteger> &nestedList) {
        for (auto &nest : nestedList) {
            if (nest.isInteger()) {
                vals.push_back(nest.getInteger());
            } else {
                dfs(nest.getList());
            }
        }
    }

public:
    NestedIterator(std::vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        cur = vals.begin();
    }

    int next() {
        return *cur++;
    }

    bool hasNext() {
        return cur != vals.end();
    }
};

class NestedIterator1 {
private:
    // pair 中存储的是列表的当前遍历位置，以及一个尾后迭代器用于判断是否遍历到了列表末尾
    std::stack<std::pair<std::vector<NestedInteger>::iterator, std::vector<NestedInteger>::iterator>> stk;

public:
    NestedIterator1(std::vector<NestedInteger> &nestedList) {
        stk.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        // 由于保证调用 next 之前会调用 hasNext，直接返回栈顶列表的当前元素，然后迭代器指向下一个元素
        return stk.top().first++->getInteger();
    }

    bool hasNext() {
        while (!stk.empty()) {
            auto &p = stk.top();
            if (p.first == p.second) { // 遍历到当前列表末尾，出栈
                stk.pop();
                continue;
            }
            if (p.first->isInteger()) {
                return true;
            }
            // 若当前元素为列表，则将其入栈，且迭代器指向下一个元素
            auto &lst = p.first++->getList();
            stk.emplace(lst.begin(), lst.end());
        }
        return false;
    }
};


#endif //ALGORITHM_NESTEDITERATOR_H
