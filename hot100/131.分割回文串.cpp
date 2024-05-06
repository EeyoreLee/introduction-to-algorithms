/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    vector<vector<string>> res;
    vector<string> stack;

public:
    vector<vector<string>> partition(string s)
    {
        traceback(s, 0);
        return res;
    }

    void traceback(string &s, int start)
    {
        if (start >= s.size())
        {
            res.push_back(stack);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome(s, start, i))
            {
                stack.push_back(s.substr(start, i - start + 1));
                traceback(s, i + 1);
                stack.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
