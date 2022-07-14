/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> window, target;
        for (auto i: p) {
            target[i]++;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        while (right < s.size()) {
            char c_s = s[right];
            if (target.count(c_s)) {
                window[c_s]++;
                if (window[c_s]==target[c_s]) {
                    count++;
                }
            }
            right++;
            while (count==target.size()) {
                if (s.substr(left, right-left).size()==p.size()) {
                    res.push_back(left);
                }
                char c_s_left = s[left];
                if (target.count(c_s_left)) {
                    if (window[c_s_left]==target[c_s_left]) {
                        count--;
                    }
                    window[c_s_left]--;
                }
                left++;
            }
        }
        return res;
    }
};
// @lc code=end

