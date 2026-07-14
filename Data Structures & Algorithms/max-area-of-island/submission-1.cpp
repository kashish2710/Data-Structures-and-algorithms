class Solution {
public:

int dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int m,int n,int count){
    vis[row][col]=1;
count=1;
 int drow[]={-1,0,1,0};
 int dcol[]={0,1,0,-1};
    for(int i=0;i<4;i++){
int nrow=row+drow[i];
int ncol=col+dcol[i];
if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
   
 count=count+ dfs(nrow,ncol,grid,vis,m,n,count);
}
    }
    return count;

}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        int m=grid.size();
        int n=grid[0].size();
      vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    
                  int area=dfs(i,j,grid,vis,m,n,0);
                  maxi=max(area,maxi);
                }
            }
        }
        return maxi;
    }
};
