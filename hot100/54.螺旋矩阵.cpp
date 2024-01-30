/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        unordered_set<int> inserted_ids;
        int i = 0, j = 0, d = 0, r;
        while (inserted_ids.size() < (matrix.size() * matrix[0].size()))
        {
            res.push_back(matrix[i][j]);
            inserted_ids.insert(matrix[0].size() * i + j);
            r = d % 4;
            if (r == 0)
            {
                j++;
            }
            else if (r == 1)
            {
                i++;
            }
            else if (r == 2)
            {
                j--;
            }
            else if (r == 3)
            {
                i--;
            }
            if (inserted_ids.count(matrix[0].size() * i + j) > 0 || i >= matrix.size() || j >= matrix[0].size())
            {
                d++;
                r = d % 4;
                if (r == 0)
                {
                    i++;
                    j++;
                }
                else if (r == 1)
                {
                    j--;
                    i++;
                }
                else if (r == 2)
                {
                    i--;
                    j--;
                }
                else if (r == 3)
                {
                    j++;
                    i--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
