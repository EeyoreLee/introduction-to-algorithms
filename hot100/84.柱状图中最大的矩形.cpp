/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> h_stack;
        int res = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!h_stack.empty() && heights[i] < heights[h_stack.top()])
            {
                int h = h_stack.top();
                h_stack.pop();
                res = max<int>(res, (i - h_stack.top() - 1) * heights[h]);
            }
            h_stack.push(i);
        }
        return res;
    }
};
// @lc code=end
