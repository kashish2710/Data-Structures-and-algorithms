class Solution {
public:
int solve(int idx,vector<int>& coins,int amount){
    if(amount==0) return 0;
    if(idx>=coins.size()){
        return 1e9;
    }
    int pick=1e9;
    if(coins[idx]<=amount){
        pick=1+solve(idx,coins,amount-coins[idx]);

    }
int skip=solve(idx+1,coins,amount);
return min(pick,skip);
}
    int coinChange(vector<int>& coins, int amount) {
        int ans= solve(0,coins,amount);
        return ans==1e9?-1:ans;
    }
};
