class Solution {
public:
int solve(int idx,vector<int>& sq,int target,vector<vector<int>>& dp){
    if(target==0)return 0;
if(idx>=sq.size())return 1e9;
if(dp[idx][target]!=-1)return dp[idx][target];
int pick=1e9;
if(sq[idx]<=target){
pick=1+solve(idx,sq,target-sq[idx],dp);
}
int skip=solve(idx+1,sq,target,dp);
return dp[idx][target]=min(pick,skip);
}
    int numSquares(int n) {
        vector<int>sq;
        for(int i=1;i*i<=n;i++){
            sq.push_back(i*i);
        }
        vector<vector<int>>dp(sq.size(),vector<int>(n+1,-1));
     return solve(0,sq,n,dp);
    }
};