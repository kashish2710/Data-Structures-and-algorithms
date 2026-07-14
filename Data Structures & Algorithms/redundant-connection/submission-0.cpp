class DSU{
public:
    vector<int>rank;
    vector<int>parent;
DSU(int n){
        rank.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }   
 }
int findUparent(int node){
    if(parent[node]==node)return node;
    return findUparent(parent[node]);
}
void union_by_rank(int u,int v){
    int ulp_u=findUparent(u);
    int ulp_v=findUparent(v);

    if(ulp_u==ulp_v)return;
    if(rank[ulp_u]>rank[ulp_v]){
        parent[ulp_v]=ulp_u;
    }
    else if(rank[ulp_u]<rank[ulp_v]){
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
        vector<int>ans;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
    
            if(dsu.findUparent(u)==dsu.findUparent(v)){
                ans.push_back(u);
                ans.push_back(v);
                }
           else {dsu.union_by_rank(u,v);}
        }
        return ans;
    }
};
