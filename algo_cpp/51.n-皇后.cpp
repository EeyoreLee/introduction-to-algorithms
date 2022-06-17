/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, "."));
        vector<vector<string>> res;
        int row = 0;
        backtrace(board, row, res, n);
        return res;
    }
    void backtrace(vector<string>& board, int row, vector<vector<string>>& res, int n) {
        for(auto col: n){
            if (isValid(board, col, row)) {
                
            }
        }
    }
    bool isValid(vector<string>& board, int col, int row) {
        return false;
    }
};
// @lc code=end

