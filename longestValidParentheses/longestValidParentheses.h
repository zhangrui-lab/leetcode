//
// Created by 张锐 on 2021/1/14.
//

#ifndef ALGORITHM_LONGESTVALIDPARENTHESES_H
#define ALGORITHM_LONGESTVALIDPARENTHESES_H

/*
 * 最长有效括号
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 *
 * 滑动窗口
 * 窗口大小不固定，选取最大合法窗口值
 * 窗口自左往右时，无法完全处理做括号较多的情况。需要自右往左在进行一次滑动窗口。
 *
 * 动态规划
 *  问题转换：
 *      dp[i] 为以s[i]结尾的最长有效括号长度。故，最长有效括号(s) = max(dp[i]), for i=0 to n;
 *  转台转移函数：
 *      s[i]='(' 时， dp[i]=0;
 *      s[i]=')' 时
 *          s[i-dp[i-1]-1]='(' 时，dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2;
 *    故：
 *      dp[i] = 0; s[i]='('
 *            = dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2; s[i]=')'
 *
 * stack
 * 利用动态规划中定义的dp函数，可以使用辅助stack结构来计算dp[i]并求出最长有效括号。
 *  stack栈底总是保持最后一个匹配失败的右括号位置。 (字符开头抽象一个永远匹配失败的字符)
 *  依次将左括号位置入栈。
 *  当遇到右括号时
 *      从栈顶中弹出匹配的左括号并记录已当前右括号结尾的最长有效括号长度。 (pos_r - stack.top);
 *      栈顶不是可匹配的左括号，更小匹配失败位置。 (stack.pop(). stack.push(r));
 *
 * 利用left，right计算dp[i]优化stack
 * 不使用额外的存储空间。
 * 自左往右进行遍历。并记录当前遍历过程中遇到的左括号left和右括号数量right。
 *  1. left < right 时： 当前前缀可能有效，继续迭代;
 *  2. left == right 时： 当前前缀为有效括号，dp[i] = left+right;
 *  3. left > right 时：当前前缀不可能有效，清空left和right记录，继续迭代;
 *  此算法在left == right时才更新有效括号最大值，故自左往右的迭代会遗漏左括号大于右括号的情况，需要自右往左进行一次更新
 */

#include <string>
#include <stack>

//滑动窗口
int longestValidParentheses1(std::string s) {
    int maxLen = 0, left = 0, right = 0;
    // 从左往右进行窗口扩展
    for (int i = 0, j = i; j < s.size(); ++j) {
        s[j] == '(' ? (left++) : (right++);
        // 当前窗口扩展为不合法状态时，扩展左窗口直至其合法
        while (left < right) {
            s[i] == '(' ? left-- : right--;
            i += 1;
        }
        if (left == right) {
            maxLen = std::max(maxLen, j - i + 1);
        }
    }
    left = right = 0;
    // 从右往左进行窗口扩展
    for (int i = s.size() - 1, j = i; j >= 0; --j) {
        s[j] == '(' ? (left++) : (right++);
        // 当前窗口扩展为不合法状态时，扩展左窗口直至其合法
        while (right < left) {
            s[i] == '(' ? left-- : right--;
            i -= 1;
        }
        if (left == right) {
            maxLen = std::max(maxLen, i - j + 1);
        }
    }
    return maxLen;
}


//动态规划
int longestValidParentheses2(std::string s) {
    int maxLen = 0;
    std::vector<int> dp(s.size(), 0);
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '(')
            continue;
        if (s[i - 1] == '(') {
            dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
        } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
            dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        }
        maxLen = std::max(maxLen, dp[i]);
    }
    return maxLen;
}


// stack
int longestValidParentheses3(std::string s) {
    int maxLen = 0;
    std::stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            int l = stk.top();
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                maxLen = std::max(maxLen, i - stk.top());
            }
        }
    }
    return maxLen;
}

// 利用left，right计算dp[i]优化stack
int longestValidParentheses4(std::string s) {
    int left = 0, right = 0, maxLen = 0;
    for (int i = 0; i < s.size(); ++i) {
        s[i] == '(' ? (left++) : (right++);
        if (left < right)
            left = right = 0;
        else if (left == right)
            maxLen = std::max(maxLen, left + right);
    }
    left = right = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        s[i] == '(' ? (left++) : (right++);
        if (right < left)
            left = right = 0;
        else if (left == right)
            maxLen = std::max(maxLen, left + right);
    }
    return maxLen;
}

#endif //ALGORITHM_LONGESTVALIDPARENTHESES_H
