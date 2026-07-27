class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int size=costs.size();
        int n=size/2;
        sort(costs.begin(),costs.end(),[](auto &a,auto &b){
            return a[0]-a[1]<b[0]-b[1];
        });
        int ans=0;
for(int i=0;i<n;i++){
   ans+=costs[i][0];
}
for(int i=n;i<size;i++){
   ans+=costs[i][1];
}
return ans;


    }
};