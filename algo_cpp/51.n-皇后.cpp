/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <string>
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        int row = 0;
        int col = 0;
        backtrace(board, res, row, n);
        return res;
    }
    void backtrace(vector<string>& board, vector<vector<string>>& res, int row, int n) {
        if (row == board.size()){
            res.push_back(board);
            return;
        }
        for(int col=0; col<n; col++){
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                backtrace(board, res, row+1, n);
                board[row][col] = '.';
            }
            else{
                continue;
            }
        }
        return;
    }
    bool isValid(vector<string>& board, int row, int col) {
        int width = board.size();
        for (int i=0; i<width; i++) {
            if (board[row][i]=='Q') {
                return false;
            }
        }
        for (int i=row; i>=0; i--) {
            if (board[i][col]=='Q') {
                return false;
            }
        }
        for (int i=row, j=col; i>=0&&j>=0; i--, j--) {
            if (board[i][j]=='Q') {
                return false;
            }
        }
        for (int i=row, j=col; i>=0&&j<width; i--, j++) {
            if (board[i][j]=='Q') {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

