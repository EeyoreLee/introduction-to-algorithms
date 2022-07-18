/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
class Solution {
public:
    unordered_map<TreeNode*, int> umap;
    int rob(TreeNode* root) {
        return dp(root);
    }

    int dp(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        if (umap.find(root)!=umap.end()) {
            return umap[root];
        }
        int rob = root->val + (root->left==nullptr ? 0 : dp(root->left->left) + dp(root->left->right)) + 
            (root->right==nullptr ? 0 : dp(root->right->left) + dp(root->right->right));
        int not_rob = dp(root->left) + dp(root->right);
        int res = max<int>(rob, not_rob);
        umap[root] = res;
        return res;
    }
};
// @lc code=end

