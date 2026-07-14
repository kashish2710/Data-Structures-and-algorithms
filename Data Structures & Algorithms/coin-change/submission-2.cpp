class Solution {
public:
int coin(int idx,vector<int>& coins, int amount){
  if(amount==0){
    return 0;
  }
  if(idx==coins.size()){
    return 1e9;//1e9 mean there is no way to get .
  }
  int skip= 0 + coin(idx+1,coins,amount);
  int pick=1e9;
  if(amount>=coins[idx]){
    pick= 1 + coin(idx,coins,amount-coins[idx]);
  }
return min(skip,pick);
}
    int coinChange(vector<int>& coins, int amount) {
   int ans= coin(0,coins,amount);
   if(ans>=1e9)return -1;
   return ans;
     
    }
};
