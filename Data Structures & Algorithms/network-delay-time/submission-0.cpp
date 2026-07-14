class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     vector<vector<pair<int,int>>>adj(n+1);
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      for(auto it:times){
        int u=it[0];
        int v=it[1];
        int t=it[2];
        adj[u].push_back({t,v});
      } 
      vector<int>dis(n+1,1e9);
      dis[k]=0;
      pq.push({0,k});
      while(!pq.empty()){
        int cost=pq.top().first;
        int node=pq.top().second;
        pq.pop();

if(cost>dis[node])continue;
        for(auto it:adj[node]){
          int weight=it.first;
          int adjnode=it.second;
          if(cost+weight<dis[adjnode]){
            dis[adjnode]=cost+weight;
            pq.push({dis[adjnode],adjnode});
          }
        }
      }
      int maxi=INT_MIN;
      for(int i=1;i<=n;i++){
        if(dis[i]==1e9)return -1;
        maxi=max(maxi,dis[i]);
      }
return maxi;
    }
};
