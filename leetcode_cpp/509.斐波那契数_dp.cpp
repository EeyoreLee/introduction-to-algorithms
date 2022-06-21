/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1){
            return 1;
        }
        int arr[] = {0, 1};
        int res;
        for (int i=2; i<=n; i++){
            res = arr[0] + arr[1];
            arr[0] = arr[1];
            arr[1] = res;
        }
        return res;
    }
};
// @lc code=end

