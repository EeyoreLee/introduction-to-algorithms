/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2, 0);
        for (int i=nums.size()-1; i>=0; i--) {
            dp[i] = max<int>(dp[i+2]+nums[i], dp[i+1]);
        }
        return dp[0];
    }
};
// @lc code=end

