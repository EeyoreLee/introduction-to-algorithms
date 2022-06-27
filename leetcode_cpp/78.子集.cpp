/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ele;
        int start = 0;
        backtrack(nums, res, start, ele);
        return res;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int start, vector<int>& ele) {
        res.push_back(ele);
        for (int i=start; i<nums.size(); i++) {
            ele.push_back(nums[i]);
            backtrack(nums, res, i+1, ele);
            ele.pop_back();
        }
        return;
    }
};
// @lc code=end

