/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    std::unordered_map<int,int> umap;
    int coinChange(vector<int>& coins, int amount) {
        umap[amount] = amount + 1;
        umap[0] = 0;
        for(int i=1; i<=amount; i++){
            for(auto c: coins){
                if (i-c<0){
                    continue;
                };
                int default_value = amount+1;
                if (umap.find(i-c)!=umap.end()){
                    default_value = umap[i-c];
                };
                int pervious_value = amount+1;
                if (umap.find(i)!=umap.end()){
                    pervious_value = umap[i];
                };
                umap[i] = min<int>(1+default_value, pervious_value);
            }
        }
        if (umap[amount]==amount+1){
            return -1;
        }
        else{
            return umap[amount];
        }
    }
};
// @lc code=end

