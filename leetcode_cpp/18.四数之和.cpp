/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSum(nums, target, 0, 4);
    }

    vector<vector<int>> nSum(vector<int>& nums, long target, int start, int n) {
        vector<vector<int>> res;
        int sz = nums.size();
        if (sz<n || n<2) {
            return res;
        }
        if (n==2) {
            int left = start;
            int right = sz-1;
            while (left < right) {
                long sum = nums[left] + nums[right];
                if (sum<target) {
                    while (left < right && nums[left]==nums[left+1]) {
                        left++;
                    }
                    left++;
                }
                else if (sum>target) {
                    while (left < right && nums[right]==nums[right-1]) {
                        right--;
                    }
                    right--;
                }
                else {
                    res.push_back({nums[left], nums[right]});
                    while (left<right && nums[left]==nums[left+1]) {
                        left++;
                    }
                    while (left<right && nums[right]==nums[right-1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        else {
            for (int i=start; i<nums.size(); i++) {
                vector<vector<int>> sub_res = nSum(nums, target-nums[i], i+1, n-1);
            
                for (vector<int>& s: sub_res) {
                    s.push_back(nums[i]);
                    res.push_back(s);
                }
                while (i<sz-1 && nums[i]==nums[i+1]) {
                    i++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

