/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> pre_sum;
        int sum = 0, res = INT_MIN, minv = INT_MAX;
        pre_sum.push_back(0);
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            pre_sum.push_back(sum);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            minv = min(minv, pre_sum[i]);
            res = max(res, pre_sum[i + 1] - minv);
        }
        return res;
    }
};
// @lc code=end
