class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        
        for(auto point: points){
           int x=point[0];
           int y=point[1];
           int dis= x*x + y*y;
           pq.push({dis,{x,y}});
        }
        vector<vector<int>>ans;
        while(k){
auto it=pq.top().second;
int x=it.first;
int y=it.second;
pq.pop();
ans.push_back({x,y});
k--;
        }
return ans;
    }
};
