class Solution {
public:
int f(int idx,vector<int>& coins,int amount){
    if(amount==0)return 0;
    if(idx>=coins.size()){
        return 1e9;
    }
    int skip=f(idx+1,coins,amount);
    int pick=1e9;
    if(coins[idx]<=amount){
        pick=1+f(idx,coins,amount-coins[idx]);
    }
    return min(pick,skip);
}
    int coinChange(vector<int>& coins, int amount) {
    int ans= f(0,coins,amount);
       if(ans>=1e9)return -1;
       return ans;
    }
};
