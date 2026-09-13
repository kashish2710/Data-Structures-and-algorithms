class Solution {
public:
int dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int m,int n){
    int area=1;
    vis[row][col]=1;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
           area+= dfs(nrow,ncol,grid,vis,m,n);
        }
    }
return area;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                 area=max(area,dfs(i,j,grid,vis,m,n));
                }
            }
        }
        return area;
    }
};
