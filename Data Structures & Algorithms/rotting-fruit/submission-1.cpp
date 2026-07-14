class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int time=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)q.push({{i,j},time});
            }
        }
        int mini=0;
        while(!q.empty()){
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
            int time=it.second;
mini=max(mini,time);
            q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                        grid[nrow][ncol]=2;  
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return mini;
    }
};
