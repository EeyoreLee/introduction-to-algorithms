/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int res = 0, fresh = 0;
        queue<pair<int, int>> q1, q2;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    q1.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        while (!q1.empty() && fresh > 0)
        {
            pair<int, int> unfresh = q1.front();
            q1.pop();
            if (unfresh.first > 0)
            {
                if (grid[unfresh.first - 1][unfresh.second] == 1)
                {
                    grid[unfresh.first - 1][unfresh.second] = 2;
                    q2.push({unfresh.first - 1, unfresh.second});
                    fresh--;
                }
            }
            if (unfresh.second > 0)
            {
                if (grid[unfresh.first][unfresh.second - 1] == 1)
                {
                    grid[unfresh.first][unfresh.second - 1] = 2;
                    q2.push({unfresh.first, unfresh.second - 1});
                    fresh--;
                }
            }
            if (unfresh.first < grid.size() - 1)
            {
                if (grid[unfresh.first + 1][unfresh.second] == 1)
                {
                    grid[unfresh.first + 1][unfresh.second] = 2;
                    q2.push({unfresh.first + 1, unfresh.second});
                    fresh--;
                }
            }
            if (unfresh.second < grid[0].size() - 1)
            {
                if (grid[unfresh.first][unfresh.second + 1] == 1)
                {
                    grid[unfresh.first][unfresh.second + 1] = 2;
                    q2.push({unfresh.first, unfresh.second + 1});
                    fresh--;
                }
            }
            if (q1.empty() || fresh == 0)
            {
                res++;
                swap(q1, q2);
            }
        }
        if (fresh == 0)
        {
            return res;
        }
        else
        {
            return -1;
        }
    }
};
// @lc code=end
