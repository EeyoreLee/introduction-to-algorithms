/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int a = jug1Capacity; // cup1 water volume
        int b = jug2Capacity; // cup2 water volume
        bool res;
        res = backtrack(a, b, targetCapacity, jug1Capacity, jug2Capacity);
        return res;
    }
    vector<int> pourAnother(int a, int aCapacity, int b, int bCapacity) {
        // pour a to b
        vector<int> res;
        int difference = b;
        if (a>=difference) {
            res.push_back(a-difference);
            res.push_back(bCapacity);
        }
        else {
            res.push_back(0);
            res.push_back(b+a);
        }
        return res;
    }
    bool backtrack(int a, int b, int targetCapacity, int jug1Capacity, int jug2Capacity) {
        if (a+b==targetCapacity) {
            return true;
        }
        if (a>targetCapacity&&(b==0||b==jug2Capacity)){
            b = 0;
            vector<int> tmp;
            tmp = pourAnother(a, jug1Capacity, b, jug2Capacity);
            a = tmp[0];
            b = tmp[1];
        }
        else if (b>targetCapacity&&(a==0||a==jug1Capacity)){
            a = 0;
            vector<int> tmp;
            tmp = pourAnother(b, jug2Capacity, a, jug1Capacity);
            b = tmp[0];
            a = tmp[1];
        }
        backtrack(a, b, targetCapacity, jug1Capacity, jug2Capacity);
        return false;
    }
};
// @lc code=end

