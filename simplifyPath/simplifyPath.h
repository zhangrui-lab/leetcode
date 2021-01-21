//
// Created by 张锐 on 2021/1/21.
//

#ifndef ALGORITHM_SIMPLIFYPATH_H
#define ALGORITHM_SIMPLIFYPATH_H

/*
 * 71. 简化路径
 *  以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
 *  在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径
 *  请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
 *
 *  使用Stack
 */

#include <string>
#include <vector>
#include <sstream>
#include <stack>

std::string simplifyPath1(std::string path) {
    std::vector<std::string> v;
    std::istringstream iss(path);
    std::string buf;
    while (getline(iss, buf, '/')) {
        if (!buf.empty() && buf != "." && buf != "..") {
            v.push_back(buf);
        } else if (!v.empty() && buf == "..") {
            v.pop_back();
        }
    }
    if (v.empty()) {
        return "/";
    }

    buf.clear();
    for (std::string &s : v) {
        buf += "/";
        buf += s;
    }
    return buf;
}

std::string simplifyPath2(std::string path) {
    std::stack<std::string> st;
    std::string dir;
    for (auto c : path) {
        if (c == '/') {
            if (dir == ".." && !st.empty()) {
                st.pop();
            } else if (dir != ".." && dir != "." && !dir.empty()) {
                st.push(dir);
            }
            dir.clear();
        } else {
            dir += c;
        }
    }

    std::string result;
    while (!st.empty()) {
        std::string s = st.top();
        st.pop();
        result = "/" + s + result;
    }
    if (result.empty())
        result = "/";
    return result;
}

#endif //ALGORITHM_SIMPLIFYPATH_H
