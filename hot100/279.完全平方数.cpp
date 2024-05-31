/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<int> dp_table;

public:
    int numSquares(int n)
    {
        dp_table.resize(n + 1, 0);
        return dp(n);
    }

    int dp(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            dp_table[i] = i;
            for (int j = 1; j * j <= i; j++)
            {
                dp_table[i] = min<int>(dp_table[i], dp_table[i - j * j] + 1);
            }
        }
        return dp_table[n];
    }
};
// @lc code=end
