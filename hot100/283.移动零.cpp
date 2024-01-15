/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int>::iterator iter;
        int n = 0;
        for (iter = nums.begin(); iter != nums.end();)
        {
            if (*iter != 0)
            {
                iter++;
            }
            else
            {
                while (*iter == 0 && iter != nums.end())
                {
                    iter = nums.erase(iter);
                    n++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            nums.push_back(0);
        }
        return;
    }
};
// @lc code=end
