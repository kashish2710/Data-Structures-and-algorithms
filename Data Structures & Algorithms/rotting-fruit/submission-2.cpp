class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                        q.push({0,{i,j}});
                }
            }
        }
        int maxtime=0;
        while(!q.empty()){
            auto it=q.front();
            int time=it.first;
            int row=it.second.first;
            int col=it.second.second;
            q.pop();
            maxtime=max(time,maxtime);
            int drow[4]={0,0,-1,1};
            int dcol[4]={1,-1,0,0};
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow < m && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                  grid[nrow][ncol]=2;
                    q.push({time+1,{nrow,ncol}});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return maxtime;
    }
};
