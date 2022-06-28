/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ele;
        sort(candidates.begin(), candidates.end());
        int sum_total=0;
        int start = 0;
        backtrack(res, ele, candidates, target, start, sum_total);
        return res;
    }
    void backtrack(vector<vector<int>>& res,
                   vector<int>& ele,
                   vector<int>& candidates,
                   int target,
                   int start,
                   int sum_total) {
        if (sum_total==target) {
            res.push_back(ele);
        }
        if (sum_total > target) {
            return;
        }
        for (int i=start; i<candidates.size(); i++) {
            if (i>start && candidates[i]==candidates[i-1]) {
                continue;
            }
            ele.push_back(candidates[i]);
            sum_total += candidates[i];
            backtrack(res, ele, candidates, target, i+1, sum_total);
            ele.pop_back();
            sum_total -= candidates[i];
        }
        return;
    }
};
// @lc code=end

