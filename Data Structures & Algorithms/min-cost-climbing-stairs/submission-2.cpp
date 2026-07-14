class Solution {
public:
int f(int i,vector<int>& cost,vector<int> &dp){
    
    if(i>=cost.size())return 0;
    if(dp[i]!=-1)return dp[i];
    int onestep= cost[i] + f(i+1,cost,dp);
    int twostep=cost[i] + f(i+2,cost,dp);
    return dp[i]=min(onestep,twostep);

}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){

        }
       return min(f(0,cost,dp),f(1,cost,dp)); 
    }
};
