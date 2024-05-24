/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq_map;
        for (int i : nums)
        {
            freq_map[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> q;
        for (const pair<int, int> &p : freq_map)
        {
            q.push({p.second, p.first});
        }
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
// @lc code=end
