/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <stack>
#include <algorithm>

using namespace std;

class MinStack
{
private:
    stack<int> raw;
    stack<int> map;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        raw.push(val);
        if (map.empty())
        {
            map.push(val);
        }
        else
        {
            map.push(min<int>(map.top(), val));
        }
    }

    void pop()
    {
        raw.pop();
        map.pop();
    }

    int top()
    {
        return raw.top();
    }

    int getMin()
    {
        return map.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
