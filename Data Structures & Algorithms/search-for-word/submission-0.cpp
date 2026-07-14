class Solution {
public:
bool DFS(int row,int col,int idx,vector<vector<char>>& board,string word,vector<vector<int>>& vis,int m , int n){
vis[row][col]=1;
if(idx==word.size()-1){
return true;
}
int drow[4]={-1,0,1,0};
int dcol[4]={0,1,0,-1};
for(int i=0;i<4;i++){
    int nrow=row+ drow[i];
    int ncol=col+ dcol[i];
    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]==word[idx+1] && !vis[nrow][ncol]){
         if(DFS(nrow,ncol,idx+1,board,word,vis,m,n))
                return true;
    }
}
 vis[row][col]=0;  
return false;

}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int idx=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[idx]){
                        if(DFS(i,j,idx,board,word,vis,m,n))return true;
                }
            }
        }
  return false;
    }
};
