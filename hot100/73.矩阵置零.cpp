/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> col_ids, ln_ids;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    ln_ids.insert(i);
                    col_ids.insert(j);
                }
            }
        }
        for (int i : ln_ids)
        {
            matrix[i] = vector<int>(matrix[0].size(), 0);
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            if (ln_ids.count(i) > 0)
            {
                continue;
            }
            for (int j : col_ids)
            {
                matrix[i][j] = 0;
            }
        }
    }
};
// @lc code=end
