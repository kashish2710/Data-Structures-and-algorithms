class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int>topo;
        vector<int>indegree(numCourses);
        for(auto it:adj){
            for(int num:it){
                indegree[num]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int adjnode:adj[node]){
                indegree[adjnode]--;
                if(indegree[adjnode]==0){
                    q.push(adjnode);
                }
            }
        }
        if(topo.size()==numCourses)return topo;
        return {};
    }
};
