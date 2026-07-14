class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n+1,1e9);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
          int u=it[0];
          int v=it[1];
          int cost=it[2];
          adj[u].push_back({v,cost});//{node,cost} cost = node tk reach krne ki 
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dis[k]=0;
        while(!pq.empty()){
          int cost=pq.top().first;
int node=pq.top().second;
pq.pop();
for(auto it:adj[node]){
  int adjnode=it.first;
  int cost_adjnode=it.second;
  if(cost+cost_adjnode < dis[adjnode]){
    dis[adjnode]=cost+cost_adjnode;
    pq.push({ dis[adjnode],adjnode});
  }
}
        }
        int maxtime=0;
for(int i=1;i<=n;i++){
  if(dis[i]==1e9)return -1;
  maxtime=max(maxtime,dis[i]);
}
return maxtime;
    }
};
