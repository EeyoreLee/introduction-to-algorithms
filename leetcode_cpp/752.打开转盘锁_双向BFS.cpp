/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
#include <string>
#include <unordered_set>
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target=="0000") {
            return 0;
        }
        vector<string> q1, q2;
        q1.push_back("0000");
        q2.push_back(target);
        unordered_set<string> deadends_set = {};
        for (auto i: deadends) {
            deadends_set.insert(i);
        }
        int step = 0;
        while (q1.size()!=0&&q2.size()!=0) {
            int sz = q1.size();
            vector<string> tmp;
            for (int i=0; i<sz; i++) {
                string secret = q1[i];
                if (deadends_set.count(secret)==1) {
                    continue;
                }
                if (isExist(q2, secret)) {
                    return step;
                }
                deadends_set.insert(secret);
                for (int j=0; j<4; j++) {
                    string plus_secret = plusOne(secret, j);
                    if (deadends_set.count(plus_secret)==0) {
                        tmp.push_back(plus_secret);
                    }
                    string minus_secret = minusOne(secret, j);
                    if (deadends_set.count(minus_secret)==0) {
                        tmp.push_back(minus_secret);
                    }
                }
            }
            step++;
            q1 = q2;
            q2 = tmp;
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
    // bool isExist(queue<string>& q, string s) {
    //     int sz = q.size();
    //     for (int i=0; i<sz; i++) {
    //         string front_string = q.front();
    //         q.pop();
    //         q.push(front_string);
    //         if (front_string==s) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    bool isExist(vector<string>& v, string s) {
        for (auto i: v) {
            if (i==s) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

