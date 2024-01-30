/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int t1, t2, t3;
        unordered_set<int> ids;
        int n = matrix.size();
        for (int i = 0; i < n / 2 + 1; i++)
        {
            for (int j = 0; j < n / 2 + 1; j++)
            {
                if (ids.count(i * n + j) > 0)
                {
                    continue;
                }
                t1 = matrix[i][j];
                t2 = matrix[j][n - 1 - i];
                t3 = matrix[n - 1 - i][n - 1 - j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[j][n - 1 - i] = t1;
                matrix[n - 1 - i][n - 1 - j] = t2;
                matrix[n - 1 - j][i] = t3;
                ids.insert(i * n + j);
                ids.insert(j * n + (n - 1 - i));
                ids.insert((n - 1 - i) * n + (n - 1 - j));
                ids.insert((n - 1 - j) * n + i);
            }
        }
    }
};
// @lc code=end
