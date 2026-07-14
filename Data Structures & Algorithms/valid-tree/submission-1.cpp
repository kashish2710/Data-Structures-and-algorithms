class DSU{
public:
    vector<int>parent;
    vector<int>rank;
DSU(int n){
    parent.resize(n);
    rank.resize(n,1);
    for(int i=0;i<n;i++){
    parent[i]=i;
}
}


int findUparent(int node){
    if(node==parent[node])return node;
    return findUparent(parent[node]);
}
void union_by_rank(int u ,int v)
{
    int ulp_u=findUparent(u);
    int ulp_v=findUparent(v);
    if(ulp_u==ulp_v)return;
    if(rank[ulp_u]>rank[ulp_v]){
        parent[ulp_v]=ulp_u;
    }
    else if(rank[ulp_v]>rank[ulp_u]){
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
    bool validTree(int n, vector<vector<int>>& edges) {
         if(edges.size() != n - 1)
            return false;
       DSU dsu(n);

       for(auto it:edges){
        int u=it[0];
        int v=it[1];
if(dsu.findUparent(u)==dsu.findUparent(v))return false;
        dsu.union_by_rank(u,v);

       }
return true;
    }
};
