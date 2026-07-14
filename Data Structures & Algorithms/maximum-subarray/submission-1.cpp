class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefix=0;
        int suffix=0;
    int n=nums.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(prefix<0 ){
            prefix=0;
        }
        if(suffix<0){
            suffix=0;
        }
        prefix=prefix+nums[i];
        suffix=suffix+nums[n-1-i];
     maxi = max(maxi, max(prefix, suffix));
    }
return maxi;
    }
};
