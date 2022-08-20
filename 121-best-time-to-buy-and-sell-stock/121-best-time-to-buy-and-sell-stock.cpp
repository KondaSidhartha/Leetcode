class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leastcp=INT_MAX;
        int currprofit=0;
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<leastcp){
                leastcp=prices[i];
            }
            currprofit=prices[i]-leastcp;
            if(currprofit>maxprofit){
                maxprofit=currprofit;
            }
        }
        return maxprofit;
    }
};