//
// Created by Administrator on 2021/7/21.
//

#ifndef ALGORITHM_REVERSEWORDS_H
#define ALGORITHM_REVERSEWORDS_H

/**
 * 151. 翻转字符串里的单词
 *  给你一个字符串 s ，逐个翻转字符串中的所有 单词 。
 *  单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 *  请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。
 *
 * 说明：
 *  输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
 *  翻转后单词间应当仅用一个空格分隔。
 *  翻转后的字符串中不应包含额外的空格。
 *
 * 求解思路:
 *  1. stack, vector等数据结构保存单词,并逆序输出到结果字符串中.
 *  2. 递归: 从 pos 处开始识别 s 的第一个字符, 并将其拼接到剩余子串的识别部分.
 *  3. 迭代: 反转字符串即, index 指向当前已正确反转的字符串位置. [start, end) 界定下一个单词 (start肯定大于index). 将[start, end)反转并拼接在index之后.
 */

#include <string>
#include <stack>

using namespace std;

static int trim(string s, int pos) {
    while (pos < s.size() && s[pos] == ' ') pos++;
    return pos;
}

string reverseWords(string s) {
    stack<string> stk;
    for (int left = trim(s, 0), right = left, size = s.size(); right <= size; ++right) {
        if (right == size) {
            if (left < right)
                stk.push(s.substr(left, right - left));
        } else if (s[right] == ' ') {
            stk.push(s.substr(left, right - left));
            left = trim(s, right);
            right = left;
        }
    }
    string str;
    while (!stk.empty()) {
        str.append(stk.top());
        stk.pop();
        if (!stk.empty())
            str.push_back(' ');
    }
    return str;
}

string reverseWords2(string s, int left) {
    left = trim(s, left);
    if (left == s.size())
        return "";
    int right = left;
    while (right != s.size() && s[right] != ' ') right++;
    string curr = s.substr(left, right - left), next = reverseWords2(s, right);
    if (!next.empty()) {
        next.push_back(' ');
    }
    return next.append(curr);
}

string reverseWords2(string s) {
    return reverseWords2(s, 0);
}

string reverseWords3(string s) {
    // 反转整个字符串
    reverse(s.begin(), s.end());
    int n = s.size();
    int idx = 0;
    for (int start = 0; start < n; ++start) {
        if (s[start] != ' ') {
            // 填一个空白字符然后将idx移动到下一个单词的开头位置
            if (idx != 0) s[idx++] = ' ';
            // 循环遍历至单词的末尾
            int end = start;
            while (end < n && s[end] != ' ') s[idx++] = s[end++];
            // 反转整个单词
            reverse(s.begin() + idx - (end - start), s.begin() + idx);
            // 更新start，去找下一个单词
            start = end;
        }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
}


#endif //ALGORITHM_REVERSEWORDS_H
