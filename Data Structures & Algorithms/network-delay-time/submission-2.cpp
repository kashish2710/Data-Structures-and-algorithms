class Solution {
public:
//pq dijkstra ko greedy bananti h pq ka use isly hota h taki phle short distances explore ho 
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     vector<vector<pair<int,int>>>adj(n+1);
     
     for(auto it:times){
      int u=it[0];
      int v=it[1];
      int cost=it[2];
adj[u].push_back({v,cost});
     }
      vector<int>dis(n+1,1e9);
      dis[k]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
      q.push({0,k});
      while(!q.empty()){
        auto it=q.top();
        int cost=it.first;
        int node=it.second;//this is the min cost to reach this node
        q.pop();
for(auto it:adj[node]){
  int adjnode=it.first;
  int weight=it.second;

  if(dis[adjnode] > cost+weight){
    dis[adjnode]=cost+weight;

    q.push({dis[adjnode],adjnode});
  }
}

      }
      int mintime=0;
      for(int i=1;i<dis.size();i++){
           if(dis[i]==1e9) return -1;
      
          mintime=max(mintime,dis[i]);
        
     
      }
      return mintime;

    }
};
