/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        int start = 1;
        vector<int> ele;
        backtrack(res, start, ele, n, k);
        return res;
    }
    void backtrack(vector<vector<int>>& res, int start, vector<int>& ele, int n, int k) {
        if (ele.size()==k) {
            res.push_back(ele);
        }
        for (int i=start; i<n+1; i++) {
            ele.push_back(i);
            backtrack(res, i+1, ele, n, k);
            ele.pop_back();
        }
        return;
    }
};
// @lc code=end

