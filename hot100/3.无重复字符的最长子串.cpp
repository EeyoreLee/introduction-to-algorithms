/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        unordered_map<char, int> map;
        int res = 1;
        int left = 0;
        int right = 0;
        while (right < s.size())
        {
            char x = s[right];
            right++;
            if (map.find(x) != map.end() && map[x] != 0)
            {
                map[x]++;
                while (map[x] > 1)
                {
                    map[s[left]]--;
                    left++;
                }
            }
            else
            {
                map[x] = 1;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
// @lc code=end
