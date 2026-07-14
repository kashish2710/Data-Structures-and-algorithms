class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
         mpp[0]=1;
         int count=0;
         int prefix=0;
         for(int num:nums){
            prefix+=num;
            if(mpp.find(prefix-k)!=mpp.end()){
                count+=mpp[prefix-k];
            }
            mpp[prefix]++;
         }
         return count;
    }
};