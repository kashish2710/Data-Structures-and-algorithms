class Solution {
public:

int path(int row,int col ,vector<vector<int>>& grid,int m,int n, vector<vector<int>>& dp){
    if(row >m-1 || row< 0|| col>n-1 || col<0)return 1e9;
    if(row==m-1 && col==n-1)return grid[m-1][n-1];
    if(dp[row][col]!=-1)return dp[row][col];
    int right=grid[row][col] + path(row,col+1,grid,m,n,dp);
    int down= grid[row][col] + path(row+1,col,grid,m,n,dp);
    return dp[row][col]= min(right,down);
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<vector<int>>dp(m,vector<int>(n,0));
            
                for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
               if (i == m - 1 && j == n - 1) {
                dp[i][j] = grid[i][j];
                continue;
            }
                int right= 1e9;
              if(j<n-1) right=grid[i][j]+dp[i][j+1];
              int down=1e9;
              if(i<m-1)down=grid[i][j]+dp[i+1][j];

              dp[i][j]=min(right,down);
            }
        }
return dp[0][0];


        // return path(0,0,grid,m,n,dp);
    }
};