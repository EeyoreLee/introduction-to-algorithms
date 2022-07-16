/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp_table(prices.size());
        for (int i=0; i<prices.size(); i++) {
            dp_table[i].resize(2);
        }
        for (int i=0; i<prices.size(); i++) {
            if (i==0) {
                dp_table[i][0] = 0;
                dp_table[i][1] = -prices[i];
                continue;
            }
            dp_table[i][0] = max<int>(dp_table[i-1][0], dp_table[i-1][1]+prices[i]);
            dp_table[i][1] = max<int>(dp_table[i-1][1], -prices[i]);
        }
        return dp_table[prices.size()-1][0];
    }
};
// @lc code=end

