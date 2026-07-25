class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int maxP = 0;

        for(int r = 0; r < prices.size(); r++){
            while(prices[l] > prices[r]){
                l = r;
            }
            maxP = max(maxP, prices[r]-prices[l]);
        }
        return maxP;
    }
};
