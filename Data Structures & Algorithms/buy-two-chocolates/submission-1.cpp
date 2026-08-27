class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n=prices.size();
        sort(prices.begin(),prices.end());
        int ori=money;
        if(prices[0]<ori){
            ori=ori-prices[0];
            if(prices[1]<=ori){
                ori-=prices[1];
                return ori;
            }
        }
      
       
            return money;
    }
};