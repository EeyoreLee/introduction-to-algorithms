/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size()==0) {
            return 0;
        }
        vector<vector<vector<int>>> dp_table(prices.size(), vector<vector<int>>(k+1,vector<int>(2,0)));
        for (int i=0; i<prices.size(); i++) {
            for (int j=1; j<k+1; j++) {
                if (i==0) {
                    dp_table[i][j][0] = 0;
                    dp_table[i][j][1] = -prices[i];
                    continue;
                }
                dp_table[i][j][0] = max<int>(dp_table[i-1][j][0], dp_table[i-1][j][1]+prices[i]);
                dp_table[i][j][1] = max<int>(dp_table[i-1][j][1], dp_table[i-1][j-1][0]-prices[i]);
            }
        }
        return dp_table[prices.size()-1][k][0];
    }
};
// @lc code=end

