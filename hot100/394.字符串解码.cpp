/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> nums;
        stack<string> strs;
        int num;
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                res += s[i];
            }
            else if (s[i] == '[')
            {
                nums.push(num);
                num = 0;
                strs.push(res);
                res = "";
            }
            else if (s[i] == ']')
            {
                int n = nums.top();
                nums.pop();
                for (int j = 0; j < n; j++)
                {
                    strs.top() += res;
                }
                res = strs.top();
                strs.pop();
            }
        }
        return res;
    }
};
// @lc code=end
