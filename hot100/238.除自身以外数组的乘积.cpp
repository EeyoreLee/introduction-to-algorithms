/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> preProd, extProd, res;
        int p = 1;
        preProd.push_back(1);
        for (int i : nums)
        {
            p *= i;
            preProd.push_back(p);
        }
        p = 1;
        extProd.push_back(1);
        for (auto i = nums.rbegin(); i != nums.rend(); i++)
        {
            p *= *i;
            extProd.push_back(p);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(preProd[i] * extProd[nums.size() - i - 1]);
        }
        return res;
    }
};
// @lc code=end
