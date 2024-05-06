/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        traceback(candidates, 0, target, 0);
        return res;
    }

    void traceback(vector<int> &candidates, int start, int target, int sum)
    {
        if (sum == target)
        {
            res.push_back(track);
        }
        else if (sum > target)
        {
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            track.push_back(candidates[i]);
            sum += candidates[i];
            traceback(candidates, i, target, sum);
            track.pop_back();
            sum -= candidates[i];
        }
    }
};
// @lc code=end
