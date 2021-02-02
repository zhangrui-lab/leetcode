//
// Created by 张锐 on 2021/2/1.
//

#ifndef ALGORITHM_ISPALINDROME_H
#define ALGORITHM_ISPALINDROME_H

/*
 * 125. 验证回文串
 *  给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 *  说明：本题中，我们将空字符串定义为有效的回文串。
 */

#include <string>

bool isPalindrome1(std::string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        while (i < j && !isalnum(s[i]))
            i++;
        while (i < j && !isalnum(s[j]))
            j--;
        if (i >= j)
            break;
        if (tolower(s[i]) != tolower(s[j]))
            return false;
    }
    return true;
}

bool isPalindrome2(std::string s) {
    std::string t;
    for (char ch: s)
        if (isalnum(ch))
            t += tolower(ch);
    std::string r(t.rbegin(), t.rend());
    return t == r;
}

#endif //ALGORITHM_ISPALINDROME_H

//"A man, a plan, a canal: Panama"