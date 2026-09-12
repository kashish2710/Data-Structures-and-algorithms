class Solution {
public:
int solve(int i,int j,vector<vector<int>>& grid,int m,int n,vector<vector<int>>& dp){
    if(i<0 || i>m-1 || j<0 || j>n-1)return 1e9;
    if(i==m-1 && j==n-1)return grid[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int down=grid[i][j]+solve(i+1,j,grid,m,n,dp);
    int right=grid[i][j]+solve(i,j+1,grid,m,n,dp);
    return dp[i][j]=min(down,right);
}
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>>dp(m+1,vector<int>(n+1,1e9));
       dp[0][1]=0;
       for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){

int right=grid[i-1][j-1]+dp[i-1][j];
int down=grid[i-1][j-1]+dp[i][j-1];
dp[i][j]=min(down,right);
        }
       }
       return dp[m][n];
// return solve(0,0,grid,m,n,dp);
    }
};