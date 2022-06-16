/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    std::unordered_map<int, int> umap;
    static bool comp(const int& a, const int& b){
        return a > b;
    };
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), comp);
        return subCoinChange(coins, amount);
    };
    int subCoinChange(vector<int>& coins, int amount){
        if (amount < 0){
            return -1;
        }
        if (amount == 0){
            return 0;
        }
        int res1 = amount + 1;
        for(int i=0; i<coins.size(); i++){
            int tmp = amount-coins[i];
            int res;
            if (umap.find(tmp)!=umap.end()){
                res = umap[tmp];
            }
            else{
                res = coinChange(coins, tmp);
                umap[tmp] = res;
            }
            if (res==-1){
                continue;
            };
            res1 = min<int>(res+1, res1);
        }
        if (res1 == amount+1){
            return -1;
        }
        return res1;
    };
};
// @lc code=end

