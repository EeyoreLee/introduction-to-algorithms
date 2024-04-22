/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> track;
    bool *used;

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        used = new bool[nums.size()]();
        traceback(nums);
        return res;
    }
    void traceback(vector<int> &nums)
    {
        if (track.size() == nums.size())
        {
            res.push_back(track);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
            {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            traceback(nums);
            track.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end
