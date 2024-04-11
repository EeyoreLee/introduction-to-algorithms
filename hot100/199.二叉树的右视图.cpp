/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode *> q1, q2;
        if (root != nullptr)
        {
            q1.push(root);
        }
        while (!q1.empty())
        {
            TreeNode *tn = q1.front();
            q1.pop();
            if (q1.empty())
            {
                res.push_back(tn->val);
            }
            if (tn->left != nullptr)
            {
                q2.push(tn->left);
            }
            if (tn->right != nullptr)
            {
                q2.push(tn->right);
            }
            if (q1.empty() && !q2.empty())
            {
                swap(q1, q2);
            }
        }
        return res;
    }
};
// @lc code=end
