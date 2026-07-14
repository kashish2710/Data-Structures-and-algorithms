class Solution {
public:
void DFS(int i,int j,int prev,vector<vector<bool>>& visited,vector<vector<int>>& heights){
      int m=heights.size();
      int n=heights[0].size();
    if(i>m-1 || j>n-1 || i<0 || j<0|| visited[i][j] || heights[i][j] < prev){
        return ;
    }
    visited[i][j]=true;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int nrow= i + drow[k];
        int ncol= j + dcol[k];
        DFS(nrow,ncol,heights[i][j],visited,heights);
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int m=heights.size();
      int n=heights[0].size();
      vector<vector<bool>>pacific(m,vector<bool>(n,false));
      vector<vector<bool>>atlantic(m,vector<bool>(n,false));
vector<vector<int>>ans;
      for(int j=0;j<n;j++){
    DFS(0,j,INT_MIN,pacific,heights);
    DFS(m-1,j,INT_MIN,atlantic,heights);
      } 
      for(int i=0;i<m;i++){
         DFS(i,0,INT_MIN,pacific,heights);
         DFS(i,n-1,INT_MIN,atlantic,heights);
      }
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(pacific[i][j] && atlantic[i][j]){
                ans.push_back({i,j});
            }
        }
      }
      return ans;
    }
};
