/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int left;
        int right;
        int sum;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            left = i + 1;
            right = nums.size() - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    vector<int> x{nums[i], nums[left], nums[right]};
                    res.push_back(x);
                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    while (nums[left] == nums[left + 1] && left + 1 < right)
                    {
                        left++;
                    }
                    left++;
                }
                else
                {
                    while (nums[right] == nums[right - 1] && left < right - 1)
                    {
                        right--;
                    }
                    right--;
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
// @lc code=end
