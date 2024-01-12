/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> string_map;
        for (string i : strs)
        {
            stringstream ss;
            vector<char> count(26, '0');
            for (char j : i)
            {
                count[j - 'a']++;
            }
            for (const auto k : count)
            {
                ss << k;
            }
            string_map[ss.str()].push_back(i);
        }
        for (auto x : string_map)
        {
            res.push_back(x.second);
        }
        return res;
    }
};
// @lc code=end
