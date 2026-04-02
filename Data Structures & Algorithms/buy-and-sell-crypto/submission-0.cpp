class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit_max=0;
        int j=1,i=0;
        while(j<prices.size())  {
            if(prices[i]>prices[j]) 
                i=j;
            profit_max=max(profit_max,prices[j]-prices[i]);
            j++;
        }
        return profit_max;
    }
};
