class Solution {
public:
void dfs(int row,int col,vector<vector<char>>& grid,int m,int n,vector<vector<int>>& vis){
vis[row][col]=1;
int drow[]={-1,0,1,0};
int dcol[]={0,-1,0,1};
for(int i=0;i<4;i++){
    int nrow=row+drow[i];
    int ncol=col+dcol[i];
    if(nrow>=0 && nrow < m && ncol>=0 && ncol< n && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
        dfs(nrow,ncol,grid,m,n,vis);
    }
}
}
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                count++;
                dfs(i,j,grid,m,n,vis);
                }
            }
        }
        return count;
    }
};
