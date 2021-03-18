//
// Created by 张锐 on 2021/3/16.
//

#ifndef ALGORITHM_SERIALIZEBINARYTREE_H
#define ALGORITHM_SERIALIZEBINARYTREE_H

/*
 * 297. 二叉树的序列化与反序列化
 *  序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 *  请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列/反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 *
 * 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 *
 * 1. 层序遍历 // 时间超出限制
 *  从 0 开始对节点进行编号。对于一个完全二叉树节点i, parent(i)=(i-1)/2, lc(i)=2i+1, rc(i)=2i+2;
 *
 * 2. DFS
 * 2. BFS
 */

#include <string>
#include <queue>
#include <list>
#include <sstream>
#include <unordered_set>
#include "../common.h"

class SerializeBinaryTree {
public:
    std::string serialize(TreeNode *root) {
        if (!root)
            return "";
        int pos = 0;
        std::string ans;
        std::unordered_set<int> nullPos;
        std::queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            if (nullPos.count(pos)) {
                nullPos.insert(2 * pos + 1);
                nullPos.insert(2 * pos + 2);
                ans += ",";
                pos++;
                continue;
            }
            root = queue.front();
            ans += std::to_string(root->val) + ",";
            queue.pop();
            if (root->left)
                queue.push(root->left);
            else
                nullPos.insert(2 * pos + 1);
            if (root->right)
                queue.push(root->right);
            else
                nullPos.insert(2 * pos + 2);
            pos++;
        }
        if (ans.size() - 1 >= 0 && ans[ans.size() - 1])
            ans.pop_back();
        return ans;
    }

    TreeNode *deserialize(std::string data) {
        auto parent = [](int i) { return i == 0 ? -1 : (i - 1) / 2; };
        auto lc = [](int p) { return 2 * p + 1; };
        int nodeNum = data.empty() ? 0 : 1;
        for (auto c:data)
            nodeNum += c == ',';
        std::vector<TreeNode *> nodes(nodeNum, nullptr);
        for (int i = 0, pos = 0, cur = INT_MIN, sym = 1; i < data.size(); ++i) {
            if (data[i] == '-') {
                sym = -1;
            } else if (data[i] != ',') {
                cur = cur == INT_MIN ? data[i] - '0' : cur * 10 + (data[i] - '0');
            } else {
                if (cur != INT_MIN) {
                    nodes[pos] = new TreeNode(cur * sym);
                }
                cur = INT_MIN;
                sym = 1;
                pos++;
            }
            if (i == data.size() - 1 && cur != INT_MIN)
                nodes[pos++] = new TreeNode(cur * sym);
        }
        for (int i = 1; i < nodeNum; ++i) {
            int p = parent(i), l = lc(p);
            if (nodes[i] && nodes[p]) {
                (l == i ? nodes[p]->left : nodes[p]->right) = nodes[i];
            }
        }
        return data.empty() ? nullptr : nodes[0];
    }
};

class SerializeBinaryTree1 {

public:
    // Encodes a tree to a single string.
    static std::string serialize(TreeNode *root) {
        if (root == NULL)
            return "X,";
        std::string leftNode = serialize(root->left);
        std::string rightNode = serialize(root->right);
        return std::to_string(root->val) + "," + leftNode + rightNode;
    }

    // Decodes your encoded data to tree.
    static TreeNode *deserialize(std::string data) {
        std::list<std::string> list = split(data, ',');
        TreeNode *res = buildTree(list);
        return res;
    }

    static TreeNode *buildTree(std::list<std::string> &strList) {
        std::string strtmp = strList.front();
        strList.pop_front();
        if (strtmp == "X")
            return NULL;
        TreeNode *node = new TreeNode(std::stoi(strtmp));
        node->left = buildTree(strList);
        node->right = buildTree(strList);
        return node;
    }

    static std::list<std::string> split(std::string &str, char c) {
        std::list<std::string> res;
        for (int lastpos = -1, pos = 0; pos < str.length(); pos++) {
            if (str[pos] == c) {
                res.push_back(str.substr(++lastpos, pos - lastpos));
                lastpos = pos;
            }
        }
        return res;
    }
};

class SerializeBinaryTree2 {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }

        std::string res;
        std::queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur) {
                res += std::to_string(cur->val) + ",";
                q.push(cur->left); // Note: this has no condition check cur->left null or not
                q.push(cur->right); // Note: this has no condition check cur->right null or not
            } else {
                res += "#,";
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if (data.empty()) {
            return nullptr;
        }

        std::stringstream ss(data);
        std::string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        std::queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (!getline(ss, str, ',')) {
                break; // run of data
            }
            if (str != "#") {
                cur->left = new TreeNode(stoi(str));
                q.push(cur->left);
            } else {
                cur->left = nullptr;
            }

            if (!getline(ss, str, ',')) {
                break; // run of data
            }
            if (str != "#") {
                cur->right = new TreeNode(stoi(str));
                q.push(cur->right);
            } else {
                cur->right = nullptr;
            }
        }

        return root;
    }
};


#endif //ALGORITHM_SERIALIZEBINARYTREE_H
