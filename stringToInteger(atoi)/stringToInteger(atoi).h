//
// Created by 张锐 on 2021/1/11.
//

#ifndef ALGORITHMS_STRINGTOINTEGER_ATOI_H
#define ALGORITHMS_STRINGTOINTEGER_ATOI_H

#include <string>

/*
 * 基于有限状态的自动机进行处理
 */

class AutoMachine {
private:
    enum Status {
        start = 0, end = 1, accept = 2, inNum = 3
    };
    enum CharType {
        empty = 0, num = 1, sym = 2, other = 3
    };
    Status trans[4][4] = {
            {end, inNum, accept, end},  // start
            {end, end,   end,    end},  // end
            {end, inNum, end,    end},  // accept
            {end, inNum, end,    end}   // inNum
    };

    Status status = start;

    CharType type(char c) {
        if (isspace(c)) return empty;
        if (c == '+' || c == '-') return sym;
        return isdigit(c) ? num : other;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        status = trans[status][type(c)];
        if (status == inNum) {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? std::min(ans, (long long) INT_MAX) : std::min(ans, -(long long) INT_MIN); // 溢出判定
        } else if (status == accept)
            sign = c == '+' ? 1 : -1;
    }
};

int myAtoi(std::string str) {
    AutoMachine automaton;
    for (char c : str)
        automaton.get(c);
    return automaton.sign * automaton.ans;
}

#endif //ALGORITHMS_STRINGTOINTEGER_ATOI_H
