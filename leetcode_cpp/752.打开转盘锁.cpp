/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
#include <queue>
#include <unordered_set>
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target=="0000") {
            return 0;
        }
        queue<string> q;
        q.push("0000");
        unordered_set<string> deadends_set = {};
        for (auto i: deadends) {
            deadends_set.insert(i);
        }
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i=0; i<sz; i++) {
                string secret = q.front();
                q.pop();
                if (deadends_set.count(secret)==1) {
                    continue;
                }
                if (secret == target) {
                    return step;
                }
                deadends_set.insert(secret);
                for (int j=0; j<4; j++) {
                    string plus_secret = plusOne(secret, j);
                    if (deadends_set.count(plus_secret)==0) {
                        q.push(plus_secret);
                    }
                    string minus_secret = minusOne(secret, j);
                    if (deadends_set.count(minus_secret)==0) {
                        q.push(minus_secret);
                    }
                }
            }
            step++;
        }
        return -1;
    }
    string plusOne(string s, int n) {
        if (s[n] == '9') {
            s[n] = '0';
        }
        else {
            s[n]++;
        }
        return s;
    }
    string minusOne(string s, int n) {
        if (s[n] == '0') {
            s[n] = '9';
        }
        else {
            s[n]--;
        }
        return s;
    }
};
// @lc code=end

