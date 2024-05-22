/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char>
            map{{'[', ']'}, {'{', '}'}, {'(', ')'}};
        vector<char> stack;
        for (char i : s)
        {
            if (!stack.empty() && map.count(stack[stack.size() - 1]) > 0 && map[stack[stack.size() - 1]] == i)
            {
                stack.pop_back();
            }
            else
            {
                stack.push_back(i);
            }
        }
        return stack.empty();
    }
};
// @lc code=end
