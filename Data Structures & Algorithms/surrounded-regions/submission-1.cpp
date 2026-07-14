class Solution {
public:
void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis){
    int m=board.size();
    int n=board[0].size();
    vis[row][col]=1;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow < m && ncol>=0 && ncol<n && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
             dfs(nrow,ncol,board,vis);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
if(board[i][0]=='O'){
    if(!vis[i][0]){
      dfs(i,0,board,vis);
    }
}  
 if(board[i][n-1]=='O'){
  if(!vis[i][n-1]){
      dfs(i,n-1,board,vis);
    }  
}
}
       for(int j=0;j<n;j++){
if(board[0][j]=='O'){
    if(!vis[0][j]){
      dfs(0,j,board,vis);
    }
}

 if(board[m-1][j]=='O'){
  if(!vis[m-1][j]){
      dfs(m-1,j,board,vis);
    }  
}
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=1){
                    board[i][j]='X';
                }
            }
        }
        
    }
};
