class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
     for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==0)q.push({i,j});
        }
     }
     while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
q.pop();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
             int ncol=col+dcol[i];
             if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==INT_MAX){
                grid[nrow][ncol]=1+grid[row][col];
                q.push({nrow,ncol});
             }
        }


     }
    }
};
