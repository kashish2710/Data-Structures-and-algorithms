class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //jab question me minimum wagera puche toh hume dijkstra
       priority_queue<
    pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>
> pq;
        pq.push({0,{0,0}});
          vector<vector<int>> dis(heights.size(), vector<int>(heights[0].size(), 1e9));
        dis[0][0] = 0;
        while(!pq.empty()){
            auto it=pq.top();
            int effort=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            if(row==heights.size()-1 && col==heights[0].size()-1)return effort;
            
            int drow[4]={0,-1,0,1};
            int dcol[4]={1,0,-1,0};
            for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
if(nrow>=0 && nrow< heights.size() && ncol>=0 && ncol<heights[0].size()){
                    int newEffort=max(effort,abs(heights[nrow][ncol]-heights[row][col]));
                    if(newEffort < dis[nrow][ncol]){
                        dis[nrow][ncol]=newEffort;
                       
                        pq.push({newEffort,{nrow,ncol}});
                    }
}
            }
        }
        return-1;
    }
};