//
// Created by 张锐 on 2021/3/19.
//

#ifndef ALGORITHM_FINDELEMENTS_H
#define ALGORITHM_FINDELEMENTS_H

/*
 * 1261. 在受污染的二叉树中查找元素
 *  给出一个满足下述规则的二叉树：
 *  root.val == 0
 *  如果 treeNode.val == x 且 treeNode.left != null，那么 treeNode.left.val == 2 * x + 1
 *  如果 treeNode.val == x 且 treeNode.right != null，那么 treeNode.right.val == 2 * x + 2
 *  现在这个二叉树受到「污染」，所有的 treeNode.val 都变成了 -1。
 * 请你先还原二叉树，然后实现 FindElements 类：
 *  FindElements(TreeNode* root) 用受污染的二叉树初始化对象，你需要先把它还原。
 *  bool find(int target) 判断目标值 target 是否存在于还原后的二叉树中并返回结果。
 */


class FindElements {
public:
    FindElements(TreeNode *root) : nums(std::vector<int>()) {
        dfs(root, 0);
    }

    bool find(int target) {
        return std::find(nums.cbegin(), nums.cend(), target) != nums.cend();
    }

private:
    std::vector<int> nums;

    void dfs(TreeNode *root, int val) {
        if (!root)
            return;
        nums.push_back(val);
        if (root->left)
            dfs(root->left, val * 2 + 1);
        if (root->right)
            dfs(root->right, val * 2 + 2);
    }
};

#endif //ALGORITHM_FINDELEMENTS_H
