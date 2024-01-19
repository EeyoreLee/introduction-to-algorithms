/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <vector>
#include <deque>

using namespace std;

class MonotonicQueue
{
private:
    deque<int> maxq;

public:
    void push(int n)
    {
        while (!maxq.empty() && n > maxq.back())
        {
            maxq.pop_back();
        }
        maxq.push_back(n);
    }
    int max()
    {
        return maxq.front();
    }
    void pop(int n)
    {
        if (n == maxq.front())
            maxq.pop_front();
    }
};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MonotonicQueue q;
        vector<int> res;
        int left = 0, right = 0;
        while (right < nums.size())
        {
            if (right < k - 1)
            {
                q.push(nums[right]);
                right++;
            }
            else
            {
                q.push(nums[right]);
                res.push_back(q.max());
                q.pop(nums[left]);
                left++;
                right++;
            }
        }
        return res;
    }
};
// @lc code=end
