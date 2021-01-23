//
// Created by 47302 on 2021/1/23.
//

#ifndef ALGORITHM_RESTOREIPADDRESSES_H
#define ALGORITHM_RESTOREIPADDRESSES_H

/*
 * 93. 复原IP地址
 *  给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 *  有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 *  例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是无效的 IP 地址。
 *
 *  DFS遍历
 */

#include <string>
#include <vector>

void restoreIpAddresses(int num, int index, std::string s, std::vector<int> &curr, std::vector<std::string> &ans) {
    if (num >= 4 && index == s.size()) {
        std::string tmp;
        for (int i = 0; i < curr.size(); ++i)
            tmp += std::to_string(curr[i]) + (i != curr.size() - 1 ? "." : "");
        ans.push_back(tmp);
        return;
    }
    if (s.length() - index < (4 - num) || s.length() - index > (4 - num) * 3)
        return;

    if (s[index] == '0') {
        curr[num] = 0;
        return restoreIpAddresses(num + 1, index + 1, s, curr, ans);
    }
    for (int hi = index, sum = 0; hi < s.size(); ++hi) {
        sum = sum * 10 + (s[hi] - '0');
        if (sum > 255)
            break;
        curr[num] = sum;
        restoreIpAddresses(num + 1, hi + 1, s, curr, ans);
    }
}

std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<std::string> ans;
    if (s.length() < 4 || s.length() > 4 * 3)
        return ans;
    std::vector<int> curr(4, 0);
    restoreIpAddresses(0, 0, s, curr, ans);
    return ans;
}

#endif //ALGORITHM_RESTOREIPADDRESSES_H
