/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return checkValidBST(root, nullptr, nullptr);
    }

private:
    bool checkValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
    {
        if (root == nullptr)
            return true;
        if (minNode != nullptr && root->val <= minNode->val)
            return false;
        if (maxNode != nullptr && root->val >= maxNode->val)
            return false;
        return checkValidBST(root->left, minNode, root) && checkValidBST(root->right, root, maxNode);
    }
};
// @lc code=end
