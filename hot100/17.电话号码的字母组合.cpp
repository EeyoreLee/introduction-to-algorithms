/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    vector<string> res;
    unordered_map<char, vector<char>> digits_map;
    string track;

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return res;
        digits_map['2'] = {'a', 'b', 'c'};
        digits_map['3'] = {'d', 'e', 'f'};
        digits_map['4'] = {'g', 'h', 'i'};
        digits_map['5'] = {'j', 'k', 'l'};
        digits_map['6'] = {'m', 'n', 'o'};
        digits_map['7'] = {'p', 'q', 'r', 's'};
        digits_map['8'] = {'t', 'u', 'v'};
        digits_map['9'] = {'w', 'x', 'y', 'z'};
        traceback(digits, 0);
        return res;
    }
    void traceback(string digits, int start)
    {
        if (track.size() == digits.size())
        {
            res.push_back(track);
        }
        for (int i = start; i < digits.size(); i++)
        {
            for (char c : digits_map[digits[i]])
            {
                track.push_back(c);
                traceback(digits, i + 1);
                track.pop_back();
            }
        }
    }
};
// @lc code=end
