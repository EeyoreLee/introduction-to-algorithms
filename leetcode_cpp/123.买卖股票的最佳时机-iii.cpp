/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp_table(prices.size(), vector<vector<int>>(2,vector<int>(2,INT_MIN)));
        for (int i=0; i<prices.size(); i++) {
            if (i==0){
                dp_table[i][0][0] = 0;
                dp_table[i][1][1] = -prices[i];
                continue;
            }
            for (int k=0; k<2; k++){
                dp_table[i][k][0] = max<int>(dp_table[i-1][k][0], dp_table[i-1][k][1]+prices[i]);
                dp_table[i][k][1] = max<int>(dp_table[i-1][k][1], dp_table[i-1][k-1][0]-prices[i]);
            }
        }
        return dp_table[prices.size()-1][0][0];
    }
};
// @lc code=end

