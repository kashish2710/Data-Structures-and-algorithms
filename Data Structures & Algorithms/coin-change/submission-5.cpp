class Solution {
public:
int solve(int idx,vector<int>& coins,int amount,vector<vector<int>>& dp){
    if(amount==0)return 0;
    if(idx>=coins.size())return 1e9;
    int pick=1e9;
    if(dp[idx][amount]!=-1)return dp[idx][amount];
    if(coins[idx]<=amount){
        pick=1+solve(idx,coins,amount-coins[idx],dp);
    }
    int skip=solve(idx+1,coins,amount,dp);
return dp[idx][amount]=min(skip,pick);

}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(0,coins,amount,dp);
       return  ans==1e9 ?-1 :ans;
   
    }
};
