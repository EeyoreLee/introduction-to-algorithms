/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int i : nums)
        {
            s.insert(i);
        }
        for (int i = 1; i < nums.size() + 1; i++)
        {
            if (s.count(i) < 1)
            {
                return i;
            }
        }
        return nums.size() + 1;
    }
};
// @lc code=end
