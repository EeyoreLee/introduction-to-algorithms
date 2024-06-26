/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size())
        {
            return;
        }
        if (j < 0 || j >= grid[0].size())
        {
            return;
        }
        if (grid[i][j] == '0')
        {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};
// @lc code=end
