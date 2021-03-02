//
// Created by 张锐 on 2021/3/2.
//

#ifndef ALGORITHM_REVERSEONLYLETTERS_H
#define ALGORITHM_REVERSEONLYLETTERS_H

/*
 * 917. 仅仅反转字母
 *  给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
 *
 * 1. 双指针
 *  不断交换前后指针指向的字母并靠拢，当前后指针临近时终止。
 * 2. 堆栈法
 *  堆栈本身可以完成序列的反转。当需要依据条件反转时只需要依据条件入栈和替换。
 */

#include <string>
#include <stack>

std::string reverseOnlyLetters(std::string s) {
    int lo = 0, hi = s.size() - 1;
    while (lo < hi) {
        while (lo < hi && !isalpha(s[lo])) lo++;
        while (lo < hi && !isalpha(s[hi])) hi--;
        if (lo < hi)
            std::swap(s[lo++], s[hi--]);
    }
    return s;
}

std::string reverseOnlyLetters1(std::string s) {
    std::stack<char> stk;
    for (auto c:s)
        if (isalpha(c))
            stk.push(c);
    int i = 0;
    while (!stk.empty()) {
        if (!isalpha(s[i])) {
            i++;
        } else {
            s[i++] = stk.top();
            stk.pop();
        }
    }
    return s;
}

#endif //ALGORITHM_REVERSEONLYLETTERS_H
