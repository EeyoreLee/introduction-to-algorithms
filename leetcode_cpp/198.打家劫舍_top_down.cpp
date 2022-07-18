/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        for (int i=0; i<nums.size(); i++) {
            if (i==0) {
                dp[i] = nums[i];
                continue;
            }
            if (i==1) {
                dp[i] = max<int>(nums[i], nums[i-1]);
                continue;
            }
            dp[i] = max<int>(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};
// @lc code=end

