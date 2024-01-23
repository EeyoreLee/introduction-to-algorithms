/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (k > nums.size())
        {
            k = k % nums.size();
        }
        std::rotate(nums.begin(), nums.begin() + (nums.size() - k), nums.end());
    }
};
// @lc code=end
