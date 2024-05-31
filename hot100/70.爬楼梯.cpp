/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> dp_table;

public:
    int climbStairs(int n)
    {
        dp_table.resize(n + 1, 0);
        return dp(n);
    }
    int dp(int n)
    {
        if (n == 1)
        {
            dp_table[n] = 1;
            return 1;
        }
        else if (n == 2)
        {
            dp_table[n] = 2;
            return 2;
        }
        else
        {
            if (dp_table[n] > 0)
            {
                return dp_table[n];
            }
            dp_table[n] = dp(n - 1) + dp(n - 2);
            return dp_table[n];
        }
    }
};
// @lc code=end
