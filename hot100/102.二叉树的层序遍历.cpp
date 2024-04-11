/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
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
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        vector<int> sub;
        queue<TreeNode *> q1, q2;
        q1.push(root);
        while (!q1.empty())
        {
            TreeNode *n = q1.front();
            q1.pop();
            sub.push_back(n->val);
            if (n->left != nullptr)
            {
                q2.push(n->left);
            }
            if (n->right != nullptr)
            {
                q2.push(n->right);
            }
            if (q1.empty())
            {
                res.push_back(sub);
                sub.clear();
                swap(q1, q2);
            }
        }
        return res;
    }
};
// @lc code=end
