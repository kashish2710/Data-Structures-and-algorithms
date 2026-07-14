class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
         int u=it[0];
         int v=it[1];
         adj[u].push_back(v);
        }
        //kahn algo- BFS
        vector<int>indegree(numCourses,0);
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            topo.push_back(i);
            }
        }
while(!q.empty()){
    int node=q.front();
    q.pop();
    for(int adjnode :adj[node]){
            indegree[adjnode]--;
            if(indegree[adjnode]==0){
                q.push(adjnode);
                topo.push_back(adjnode);
            }
    }
}
return topo.size()==numCourses;
    }
};
