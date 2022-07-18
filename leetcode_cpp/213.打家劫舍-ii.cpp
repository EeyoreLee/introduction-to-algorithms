/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0) {
            return 0;
        }
        if (nums.size()==1) {
            return nums[0];
        }
        return max<int>(subRob(nums, 0, nums.size()-1), subRob(nums, 1, nums.size()));
    }

    int subRob(vector<int>& nums, int start, int end) {
        vector<int> dp(end-start+2, 0);
        for (int i=end-start-1; i>=0; i--) {
            dp[i] = max<int>(dp[i+2]+nums[i+start], dp[i+1]);
        }
        return dp[0];
    }
};
// @lc code=end

