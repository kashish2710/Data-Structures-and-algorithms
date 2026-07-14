class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= end){
               end=max(end,intervals[i][1]);
               ans.back()[1]=end;
            }
           else { 
            ans.push_back(intervals[i]);
            end=ans.back()[1];
           }
        }
return ans;
    }
};
