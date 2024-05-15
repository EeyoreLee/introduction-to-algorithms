/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int k = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] < nums[i])
            {
                k = i + 1;
            }
        }
        int idx = searchIndex(nums, target, k);
        return idx;
    }
    int searchIndex(vector<int> &nums, int target, int k)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                if (mid > k)
                {
                    right = mid - 1;
                }
                else
                {
                    if (nums[left] > target)
                    {

                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
            }
            else if (nums[mid] < target)
            {
                if (mid < k)
                {
                    left = mid + 1;
                }
                else
                {
                    if (nums[right] >= target)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
