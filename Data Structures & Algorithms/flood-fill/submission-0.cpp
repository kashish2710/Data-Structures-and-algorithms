class Solution {
public:
void dfs(int row,int col,vector<vector<int>>&image,int color,vector<vector<int>>&vis,int start_color,int m,int n){
    vis[row][col]=1;
    image[row][col]=color;
    int drow[]={-1,0,1,0};
    int dcol[]={0,-1,0,1};
    for(int i=0;i<4;i++){
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&!vis[nrow][ncol] && image[nrow][ncol]==start_color){

dfs(nrow,ncol,image,color,vis,start_color,m,n);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     int m=image.size();
     int n=image[0].size();
       int start_color=image[sr][sc];
       vector<vector<int>>vis(m,vector<int>(n,0));
    if(image[sr][sc]!=color){ 
        dfs(sr,sc,image,color,vis,start_color,m,n);
        }
return image;
    }
};