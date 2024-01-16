/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        vector<int> stack;
        for (int i = 0; i < height.size(); i++)
        {
            while (!stack.empty() && height[stack.back()] < height[i])
            {
                int w = stack.back();
                int h = height[w];
                stack.pop_back();
                if (stack.empty())
                    break;
                int width = i - stack.back() - 1;
                res += width * (min(height[stack.back()], height[i]) - h);
            }
            stack.push_back(i);
        }
        return res;
    }
};
// @lc code=end
