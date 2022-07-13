/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window, target;
        for (auto i: s1) {
            target[i]++;
        } 
        int left = 0;
        int right = 0;
        int count = 0;
        while (right < s2.size()) {
            char c_s2 = s2[right];
            if (target.count(c_s2)) {
                window[c_s2]++;
                if (window[c_s2]==target[c_s2]) {
                    count++;
                }
            }
            right++;
            while (count==target.size()) {
                if (s2.substr(left, right-left).size()==s1.size()) {
                    return true;
                }
                char c_t2 = s2[left];
                if (target.count(c_t2)) {
                    if (window[c_t2]==target[c_t2]) {
                        count--;
                    }
                    window[c_t2]--;
                }
                left++;
            }
        }
        return false;
    }
};
// @lc code=end

