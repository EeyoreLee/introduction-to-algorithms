/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        map[0] = 1;
        int res = 0;
        int pre = 0;
        for (int i : nums)
        {
            pre += i;
            if (map.find(pre - k) != map.end())
            {
                res += map[pre - k];
            }
            if (map.find(pre) != map.end())
            {
                map[pre] += 1;
            }
            else
            {
                map[pre] = 1;
            }
        }
        return res;
    }
};
// @lc code=end
