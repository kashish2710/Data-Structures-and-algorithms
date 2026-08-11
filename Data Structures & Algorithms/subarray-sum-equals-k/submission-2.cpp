class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
int prefix=0;
int count=0;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            if(mpp.find(prefix-k)!=mpp.end()){
count+=mpp[prefix-k];
            }
        mpp[prefix]++;
        }
        return count;
    }
};