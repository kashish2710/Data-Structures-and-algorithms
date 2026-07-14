class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       queue<pair<int,pair<int,int>>>q;
       vector<vector<pair<int,int>>>adj(n);

      for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
vector<int>dis(n,1e9);
dis[src]=0;
q.push({0,{src,0}});
while(!q.empty()){
    auto it=q.front();
    int stops=it.first;
    int node=it.second.first;
    int cost=it.second.second;
    q.pop();

    for(auto it:adj[node]){
        int adjnode=it.first;
        int weight=it.second;

        if(cost+weight<dis[adjnode] && stops<=k){
            dis[adjnode]=cost+weight;
            q.push({stops+1,{adjnode,dis[adjnode]}});
        }
    }

}


return dis[dst]==1e9 ?  -1 : dis[dst];
    }

};
