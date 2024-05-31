/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<int> dp_table;

public:
    int rob(vector<int> &nums)
    {
        dp_table.resize(nums.size(), -1);
        return dp(nums, 0);
    }

    int dp(vector<int> &nums, int start)
    {
        if (start >= nums.size())
        {
            return 0;
        }
        if (dp_table[start] > -1)
        {
            return dp_table[start];
        }
        int m = max<int>(dp(nums, start + 1), dp(nums, start + 2) + nums[start]);
        dp_table[start] = m;
        return m;
    }
};
// @lc code=end
