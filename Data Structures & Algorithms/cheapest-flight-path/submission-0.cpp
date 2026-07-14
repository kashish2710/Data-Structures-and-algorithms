class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
        vector<int>distance(n,1e9);
        distance[src]=0;
        queue<pair<int,pair<int,int>>>q;

        q.push({0,{src,0}});//{stops,{node,cost}};
        while(!q.empty()){
            auto it=q.front();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            q.pop();
// if(stops>k)continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int weight=it.second;
                if(cost + weight < distance[adjnode] && stops<=k){
                    distance[adjnode]=cost + weight;
                    q.push({stops+1,{adjnode,distance[adjnode]}});
                }
            }
        }
if(distance[dst]==1e9)return -1;
return distance[dst];

    }
};
