class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
        queue<pair<int,pair<int,int>>>q;
        int m=grid.size();
        int n=grid[0].size();
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
maxtime=max(maxtime,time);
q.pop();
int drow[]={-1,0,1,0};
int dcol[]={0,-1,0,1};
for(int i=0;i<4;i++){
int nrow=row+drow[i];
int ncol=col+dcol[i];
if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
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
