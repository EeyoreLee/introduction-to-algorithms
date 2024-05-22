/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> ids;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!ids.empty() && temperatures[i] > temperatures[ids.top()])
            {
                int idx = ids.top();
                ids.pop();
                res[idx] = i - idx;
            }
            ids.push(i);
        }
        return res;
    }
};
// @lc code=end
