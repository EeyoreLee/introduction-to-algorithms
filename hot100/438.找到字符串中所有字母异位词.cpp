/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        unordered_map<char, int> map_p, map_s;
        if (p.size() > s.size())
            return res;
        int left = 0, right = 0;
        while (right < p.size())
        {
            map_p[p[right]]++;
            map_s[s[right]]++;
            right++;
        }
        right--;
        while (right < s.size())
        {
            if (map_s == map_p)
            {
                res.push_back(left);
            }
            right++;
            map_s[s[right]]++;
            if (map_s[s[left]] == 1)
            {
                map_s.erase(s[left]);
            }
            else
            {
                map_s[s[left]]--;
            }
            left++;
        }
        return res;
    }
};
// @lc code=end
