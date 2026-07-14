class Solution {
public:
int DFS(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int m,int n){
    vis[row][col]=1;
    int area=1;
    int drow[4]={0,0,-1,1};
    int dcol[4]={1,-1,0,0};
    for(int i=0;i<4;i++){
        int nrow= row + drow[i];
        int ncol= col + dcol[i];
      if(nrow >=0 && nrow < m &&
           ncol>=0 && ncol < n &&
           !vis[nrow][ncol] &&
           grid[nrow][ncol]==1){ 
        area+=DFS(nrow,ncol,grid,vis,m,n);
    }
    }
return area;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxArea=0;
  vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                int area= DFS(i,j,grid,vis,m,n);
                maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};
