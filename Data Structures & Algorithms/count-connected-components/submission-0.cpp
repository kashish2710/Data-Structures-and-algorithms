//a parent of itself mean new component
 class DSU{
    public:
vector<int>rank,parent;
    DSU(int n){
        rank.resize(n+1,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;        }
        
    }

    int findparent(int node){
        if(parent[node]==node)return node;
        return findparent(parent[node]);
    }
    void union_by_rank(int u,int v){
int ulp_u=findparent(u);
int ulp_v=findparent(v);
if(ulp_u==ulp_v)return ;
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

    int countComponents(int n, vector<vector<int>>& edges) {
      DSU dsu(n);
         for(auto it:edges){
            int u=it[0];
            int v=it[1];
            dsu.union_by_rank(u,v);
         }
         int count=0;

         for(int i=0;i<n;i++){
            if(dsu.findparent(i)==i)count++;
         }
         return count;
    }
};
