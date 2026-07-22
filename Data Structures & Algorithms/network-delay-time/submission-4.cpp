class Solution {
public:
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
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
          auto it=pq.top();
          int cost=it.first;
          int node=it.second;
          pq.pop();
          for(auto it:adj[node]){
            int adjnode=it.first;
            int adjcost=it.second;
            if(dis[adjnode]>cost+adjcost){
              dis[adjnode]=cost + adjcost;
              pq.push({dis[adjnode],adjnode});
            }
        }
        }
        int mini=0;
for(int i=1;i<=n;i++){
  if(dis[i]==1e9)return -1;
  mini=max(mini,dis[i]);
}
return mini;
    }
};
