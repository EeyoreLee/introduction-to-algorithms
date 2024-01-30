/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix[0][0] > target || matrix[matrix.size() - 1][matrix[0].size() - 1] < target)
        {
            return false;
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == target)
            {
                return true;
            }
            if (matrix[i][0] > target)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    if (matrix[i - 1][j] == target)
                    {
                        return true;
                    }
                }
            }
            if (i == matrix.size() - 1)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    if (matrix[i][j] == target)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
