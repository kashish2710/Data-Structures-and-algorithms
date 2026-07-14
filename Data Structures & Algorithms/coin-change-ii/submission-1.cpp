class Solution {
public:
int coin(int idx,vector<int>& coins,int amount,vector<vector<int>>& dp){
    if(amount==0)return 1;
    if(idx==coins.size())return 0;
    if( dp[idx][amount]!=-1)return  dp[idx][amount];
    //skip
    int skip=coin(idx+1,coins,amount,dp);
    //pick
    int pick=0;
    if(coins[idx]<=amount){
        pick=coin(idx,coins,amount-coins[idx],dp);
    }
    return dp[idx][amount]=pick+skip;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return coin(0,coins,amount,dp);
    }
};
