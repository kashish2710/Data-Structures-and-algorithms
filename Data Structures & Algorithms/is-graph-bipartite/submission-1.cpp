class Solution {
public:
bool dfs(int node,int color,vector<vector<int>>& graph,vector<int>& vis,vector<int>& colour){
    vis[node]=1;
    colour[node]=color;
    for(int adjnode:graph[node]){
         if (vis[adjnode]) {
                if (colour[adjnode] == color) {
                    return false;
                }
            }
        else{
            if(!dfs(adjnode,!color,graph,vis,colour))return false;
        }


    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
int n=graph.size();
vector<int>vis(n,0);
vector<int>colour(n,-1);
for(int i=0;i<n;i++){
    if (!vis[i]) {
                if (!dfs(i, 0, graph, vis, colour)) {
                    return false;
                }
            }
}
return true;
    }
};
