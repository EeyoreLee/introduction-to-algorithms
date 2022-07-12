/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, target;
        for (auto i: t) {
            target[i]++;
        }
        int len = 999999;
        int left = 0;
        int right = 0;
        int count = 0;
        int start = 0;
        while (right < s.size()) {
            char cs = s[right];
            if (target.count(cs)) {
                window[cs]++;
                if (window[cs]==target[cs]) {
                    count++;
                }
            }
            right++;
            while (count==target.size()) {
                char ct = s[left];
                if (right-left<len) {
                    len = right - left;
                    start = left;
                }
                if (target.count(ct)) {
                    if (window[ct]==target[ct]) {
                        count--;
                    }
                    window[ct]--;
                }
                left++;
            }
        }
        if (len < 999999) {
            return s.substr(start, len);
        }
        return "";
    }
};
// @lc code=end

