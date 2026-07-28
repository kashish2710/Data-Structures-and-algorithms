class DSU{
    public:
    vector<int>rank;
    vector<int>parent;
DSU(int n){
parent.resize(n);
rank.resize(n,1);
for(int i=0;i<n;i++){
    parent[i]=i;
}
}
int findparent(int node){
    if(parent[node]==node)return node;
    return parent[node]=findparent(parent[node]);
}
void union_rank(int u,int v){
    int ulp_u=findparent(u);
    int ulp_v=findparent(v);
    if(ulp_u==ulp_v)return;
    if(rank[ulp_u]>rank[ulp_v]){
        parent[ulp_v]=ulp_u;
    }
    else  if(rank[ulp_v]>rank[ulp_u]){
        parent[ulp_u]=ulp_v;
    }
    else{
        rank[ulp_u]++;
        parent[ulp_v]=ulp_u;
    }
}



};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
    
        int m=points.size();
          DSU dsu(m);
        vector<vector<int>>edges;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int dis=abs(x2-x1)+abs(y2-y1);
                edges.push_back({dis,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        int cost=0;
        for(auto it:edges){
            int dis=it[0];
            int u=it[1];
            int v=it[2];
            if(dsu.findparent(u)!=dsu.findparent(v)){
                dsu.union_rank(u,v);
                cost+=dis;
            }
        }
        return cost;
    }
};
