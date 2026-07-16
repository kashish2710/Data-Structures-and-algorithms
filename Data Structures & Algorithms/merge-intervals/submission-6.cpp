class Solution {
public:
 
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end){
               ans.back()[1]=max(end,intervals[i][1]);
              
            }
            else{
             ans.push_back(intervals[i]);}

              end= ans.back()[1];
        }
        return ans;
    }
};
