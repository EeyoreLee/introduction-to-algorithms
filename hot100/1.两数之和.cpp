/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        vector<size_t> index_vector(nums.size());
        iota(index_vector.begin(), index_vector.end(), 0);
        sort(index_vector.begin(), index_vector.end(), [&nums](size_t i, size_t j)
             { if (nums [i]==nums[j]) {
                return i < j;
             } return nums[i]<nums[j]; });
        int left = 0;
        int right = index_vector.size() - 1;
        while (left < right)
        {
            if (nums[index_vector[left]] + nums[index_vector[right]] == target)
            {
                res.push_back(index_vector[left]);
                res.push_back(index_vector[right]);
                return res;
            }
            else if (nums[index_vector[left]] + nums[index_vector[right]] < target)
            {
                while (nums[index_vector[left]] == nums[index_vector[left + 1]] && left + 1 < right)
                {
                    left++;
                }
                left++;
            }
            else
            {
                while (nums[index_vector[right]] == nums[index_vector[right - 1]] && left < right - 1)
                {
                    right--;
                }
                right--;
            }
        }
        return res;
    }
};
// @lc code=end
