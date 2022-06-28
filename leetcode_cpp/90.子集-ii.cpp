/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ele;
        int start = 0;
        backtrack(res, nums, start, ele);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int start, vector<int>& ele) {
        res.push_back(ele);
        for (int i=start; i<nums.size(); i++) {
            if (i>start && nums[i]==nums[i-1]) {
                continue;
            }
            ele.push_back(nums[i]);
            backtrack(res, nums, i+1, ele);
            ele.pop_back();
        }
        return;
    }
};
// @lc code=end

