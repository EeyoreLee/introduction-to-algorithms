/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
#include <queue>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        unordered_set<pair<int, int>, pair_hash> visited={};
        queue<pair<int, int>> q;
        q.emplace(0,0);
        while (!q.empty()) {
            if (visited.count(q.front())!=0) {
                q.pop();
                continue;
            }
            auto[a, b] = q.front();
            if (a==targetCapacity||b==targetCapacity||(a+b)==targetCapacity) {
                return true;
            }
            visited.insert(q.front());
            q.pop();
            q.emplace(jug1Capacity,b);
            q.emplace(a,jug2Capacity);
            q.emplace(a,0);
            q.emplace(0,b);
            int difference_a = jug1Capacity-a;
            if (b>=difference_a) {
                q.emplace(jug1Capacity, b-difference_a);
            }
            else {
                q.emplace(a+b, 0);
            }
            int difference_b = jug2Capacity-b;
            if (a>=difference_b) {
                q.emplace(a-difference_b, jug2Capacity);
            }
            else {
                q.emplace(0,a+b);
            }
        }
        return false;
    }
    struct pair_hash {
        inline std::size_t operator()(const std::pair<int,int> & v) const {
            return v.first*31+v.second;
            // std::hash<int> int_hasher;
            // return int_hasher(v.first) ^ int_hasher(v.second);
        }
    };
};
// @lc code=end

