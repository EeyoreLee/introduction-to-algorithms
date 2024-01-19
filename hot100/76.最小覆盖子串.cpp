/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool valid(unordered_map<char, int> &t, unordered_map<char, int> &w)
    {
        char key;
        for (auto i : t)
        {
            key = i.first;
            if (w.find(key) == w.end())
            {
                return false;
            }
            if (t[key] > w[key])
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        unordered_map<char, int> tmap, wmap;
        string res;
        for (char c : t)
        {
            if (tmap.find(c) != tmap.end())
            {
                tmap[c]++;
            }
            else
            {
                tmap[c] = 1;
            }
        }
        int left = 0, right = 0;
        while (right < s.size())
        {
            if (tmap.find(s[right]) != tmap.end())
            {
                if (wmap.find(s[right]) != wmap.end())
                {
                    wmap[s[right]]++;
                }
                else
                {
                    wmap[s[right]] = 1;
                }
            }
            while (left <= right && valid(tmap, wmap))
            {
                if (wmap.find(s[left]) != wmap.end())
                {
                    if (wmap[s[left]] > tmap[s[left]])
                    {
                        wmap[s[left]]--;
                    }
                    else
                    {
                        if (res.empty() || s.substr(left, right - left + 1).size() < res.size())
                        {
                            res = s.substr(left, right - left + 1);
                        }
                        if (wmap[s[left]] == 1)
                        {
                            wmap.erase(s[left]);
                        }
                        else
                        {
                            wmap[s[left]]--;
                        }
                    }
                }
                left++;
            }
            right++;
        }
        return res;
    }
};
// @lc code=end
