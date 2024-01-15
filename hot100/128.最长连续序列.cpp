/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() < 1)
        {
            return 0;
        }
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator iter;
        unordered_set<int> set;
        for (auto i : nums)
        {
            set.insert(i);
        }
        int res = 1;
        int n = 1;
        for (auto i : nums)
        {
            if (map.find(i) != map.end())
            {
                continue;
            }
            for (int j = 1; j <= nums.size(); ++j)
            {
                if ((iter = map.find(i + j)) != map.end())
                {
                    n += iter->second;
                    break;
                }
                else
                {
                    if (set.count(i + j) > 0)
                    {
                        n++;
                        map[i + j] = n;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            map[i] = n;
            if (n > res)
            {
                res = n;
            }
            n = 1;
        }
        return res;
    }
};
// @lc code=end
