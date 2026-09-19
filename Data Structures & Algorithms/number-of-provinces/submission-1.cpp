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
    if(parent[node]==node)return node;
    return parent[node]=findparent(parent[node]);
}
void unionRank(int u,int v){
    int ulp_u=findparent(u);
    int ulp_v=findparent(v);
    if(ulp_u==ulp_v)return;
    if(rank[ulp_u]>rank[ulp_v]){
        parent[ulp_v]=ulp_u;
    }
    else if(rank[ulp_v]>rank[ulp_u]){
        parent[ulp_u]=ulp_v;
    }
    else {
        parent[ulp_v]=ulp_u;
        rank[ulp_u]++;
    }


}

};

class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
                 int n=isConnected.size();
        DSU dsu(n);

   
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                  dsu.unionRank(i,j);
                    
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
if(dsu.findparent(i)==i)count++;
        }
       return count;
    }
};