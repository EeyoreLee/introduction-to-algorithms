/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
#include <queue>

using namespace std;

class MedianFinder
{
private:
    priority_queue<int, vector<int>, less<>> small;
    priority_queue<int, vector<int>, greater<>> large;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (small.size() >= large.size())
        {
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        else
        {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian()
    {
        if (small.size() == large.size())
        {
            return small.top() / 2.0 + large.top() / 2.0;
        }
        else if (small.size() < large.size())
        {
            return large.top();
        }
        else
        {
            return small.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
