/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> track;

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        traceback(nums, 0);
        return res;
    }
    void traceback(vector<int> &nums, int start)
    {
        res.push_back(track);
        for (int i = start; i < nums.size(); i++)
        {
            track.push_back(nums[i]);
            traceback(nums, i + 1);
            track.pop_back();
        }
    }
};
// @lc code=end
