class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue< pair<int,int>, vector<pair<int,int>>>pq;
        unordered_map<int,int>mpp;
        for(int num:nums){
            mpp[num]++;
        }
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k!=0){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
            k--;
        }
return ans;
    }
};
