/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
#include <queue>
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left==nullptr&&node->right==nullptr) {
                    return depth;
                }
                if (node->left!=nullptr) {
                    q.push(node->left);
                }
                if (node->right!=nullptr) {
                    q.push(node->right);
                }
            }
            depth++;
        }
        return -1;
    }
};
// @lc code=end

