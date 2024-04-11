/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> v_list;

public:
    int kthSmallest(TreeNode *root, int k)
    {
        traverse(root, k);
        return v_list.back();
    }

private:
    void traverse(TreeNode *root, int k)
    {
        if (root == nullptr || v_list.size() == k)
        {
            return;
        }
        traverse(root->left, k);
        if (v_list.size() < k)
        {
            v_list.push_back(root->val);
        }
        traverse(root->right, k);
    }
};
// @lc code=end
