/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ele;
        vector<bool> visited(nums.size(), false);
        int start=0;
        backtrack(res, ele, nums, visited, start);
        return res;
    }
    void backtrack(vector<vector<int>>& res,
                   vector<int>& ele,
                   vector<int>& nums,
                   vector<bool>& visited,
                   int start) {
        if (ele.size()==nums.size()) {
            res.push_back(ele);
        }
        for (int i=0; i<nums.size(); i++) {
            if (visited[i]==true) {
                continue;
            }
            if (i>0 && nums[i]==nums[i-1] && !visited[i-1]) {
                continue;
            }
            ele.push_back(nums[i]);
            visited[i] = true;
            backtrack(res, ele, nums, visited, start+1);
            ele.pop_back();
            visited[i] = false;
        }
        return;
    }
};
// @lc code=end

