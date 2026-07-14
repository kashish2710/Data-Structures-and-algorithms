class Solution {
public:
void dfs(int node,vector<int>& vis,vector<vector<int>>&adj){
    vis[node]=1;
    for(int adjnode:adj[node]){
        if(!vis[adjnode]){
            dfs(adjnode,vis,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
              count++;
              dfs(i,vis,adj);

            }
        }
        return count;
    }
};