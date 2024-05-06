/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    vector<string> res;
    string string_stack;

public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
        {
            return res;
        }
        traceback(0, 0, n);
        return res;
    }

    void traceback(int num_left, int num_right, int n)
    {
        if (num_left == n && num_right == n)
        {
            res.push_back(string_stack);
            return;
        }
        if (num_left < num_right)
        {
            return;
        }
        if (num_left > n || num_right > n)
        {
            return;
        }

        string_stack.push_back('(');
        traceback(num_left + 1, num_right, n);
        string_stack.pop_back();

        string_stack.push_back(')');
        traceback(num_left, num_right + 1, n);
        string_stack.pop_back();
    }
};
// @lc code=end
