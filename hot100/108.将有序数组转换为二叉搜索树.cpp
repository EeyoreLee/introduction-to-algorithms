/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return traverse(nums, 0, nums.size());
    }

private:
    TreeNode *traverse(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode *tn = new TreeNode(nums[mid]);
        tn->left = traverse(nums, left, mid);
        tn->right = traverse(nums, mid + 1, right);
        return tn;
    }
};
// @lc code=end
