/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> used;
        subPermute(res, nums, used);
        return res;
    }
    void subPermute(vector<vector<int>>& res, vector<int>& nums, vector<int>& used) {
        if (used.size()==nums.size()) {
            res.insert(res.end(), used);
            return;
        }
        for(auto n: nums) {
            if (find(used.begin(), used.end(), n)!=used.end()) {
                continue;
            }
            used.insert(used.end(), n);
            subPermute(res, nums, used);
            used.pop_back();
        }
    }
};
// @lc code=end

