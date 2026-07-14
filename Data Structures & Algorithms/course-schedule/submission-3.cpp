class Solution {
public:
bool dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& vis,vector<int>& path){
    vis[node]=1;
    path[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
           if(dfs(it,node,adj,vis,path))return true;
        }
       else if(path[it])return true;
    }
     path[node]=0;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        int n=numCourses;
        vector<int>vis(n,0);
        vector<int>path(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
               if(dfs(i,-1,adj,vis,path))return false; 
            }
        }
        return true;
    }
};
