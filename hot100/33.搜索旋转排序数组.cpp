/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                if (nums[left] < nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    if (nums[mid] >= nums[left])
                    {
                        left = mid + 1;
                    }
                    else if (nums[mid] < nums[left])
                    {
                        if (nums[left] > target)
                        {
                            left = mid + 1;
                        }
                        else if (nums[left] <= target)
                        {
                            right = mid - 1;
                        }
                    }
                }
            }
            else if (nums[mid] > target)
            {
                if (nums[left] < nums[right])
                {
                    right = mid - 1;
                }
                else
                {
                    if (nums[mid] < nums[left])
                    {
                        right = mid - 1;
                    }
                    else if (nums[mid] >= nums[left])
                    {
                        if (nums[left] > target)
                        {
                            left = mid + 1;
                        }
                        else if (nums[left] <= target)
                        {
                            right = mid - 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
