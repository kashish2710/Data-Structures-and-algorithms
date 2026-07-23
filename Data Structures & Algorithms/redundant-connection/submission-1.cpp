class DSU{
public:
vector<int>rank;
    vector<int>parent;
DSU(int n){
   rank.resize(n+1,1);
parent.resize(n+1);
for(int i=0;i<n;i++){
    parent[i]=i;
} 
}

int findparent(int node){
    if(node==parent[node])return node;
    return findparent(parent[node]);
}
void unionrank(int u,int v){
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
         parent[ulp_v]=ulp_u;
         rank[ulp_u]++;
    }
}

};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
           if( dsu.findparent(u)!=dsu.findparent(v)){
                dsu.unionrank(u,v);
            }
            else{
return {u,v};
            }
        }
        return {};
    }
};
