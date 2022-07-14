/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int res = 0;
        int left = 0;
        int right = 0;
        while (right < s.size())
        {
            char s_r = s[right];
            window[s_r]++;
            right++;
            while (window[s_r]>1)
            {
                char s_l = s[left];
                window[s_l]--;
                left++;
            }
            if (right-left>res) {
                res = right-left;
            }
        }
        return res;
    }
};
// @lc code=end

