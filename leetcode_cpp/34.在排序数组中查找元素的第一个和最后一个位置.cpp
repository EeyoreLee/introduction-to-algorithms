/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range = {-1, -1};
        if (nums.size()==0) {
            return range;
        }
        int left = 0;
        int right = nums.size()-1;
        int mid;

        while (left<=right) {
            mid = left + (right - left) / 2;
            if (nums[mid]==target) {
                right = mid-1;
            }
            else if (nums[mid]<target) {
                left = mid+1;
            }
            else if (nums[mid]>target) {
                right = mid-1;
            }
        }
        if (left > nums.size()-1) {
            return range;
        }
        if (nums[left]!=target) {
            return range;
        }
        range[0] = left;
        left = 0;
        right = nums.size()-1;
        while (left<=right) {
            mid = left + (right - left) / 2;
            if (nums[mid]==target) {
                left = mid+1;
            }
            else if (nums[mid]<target) {
                left = mid + 1;
            }
            else if (nums[mid]>target) {
                right = mid - 1;
            }
        }
        range[1] = right;
        return range;
    }
};
// @lc code=end

