/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ele;
        int start=0;
        int sum_total=0;
        backtrack(res, ele, candidates, target, sum_total, start);
        return res;
    }
    void backtrack(vector<vector<int>>& res,
                   vector<int>& ele,
                   vector<int>& candidates,
                   int target,
                   int sum_total,
                   int start) {
        if (sum_total==target) {
            res.push_back(ele);
        }
        if (sum_total>target) {
            return;
        }
        for (int i=start; i<candidates.size(); i++) {
            ele.push_back(candidates[i]);
            sum_total += candidates[i];
            backtrack(res, ele, candidates, target, sum_total, i);
            ele.pop_back();
            sum_total -= candidates[i];
        }
        return;
    }
};
// @lc code=end

