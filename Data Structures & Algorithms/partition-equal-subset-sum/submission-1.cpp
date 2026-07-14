class Solution {
public:
bool f(int idx,vector<int>& nums,int target,vector<vector<int>>& dp){
if(target==0)return true;
if(idx==nums.size())return false;
if(dp[idx][target]!=-1)return dp[idx][target];
bool skip=f(idx+1,nums,target,dp);
bool take=false;
if(nums[idx]<=target){
    take=f(idx+1,nums,target-nums[idx],dp);
}
return dp[idx][target]=skip || take ;
}
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int num:nums){
            total+=num;
        }
        if(total % 2 != 0) return false;
        int ntarget=total / 2 ;
        vector<vector<int>>dp(nums.size(),vector<int>(ntarget+1,-1));
        return f(0,nums,ntarget,dp);
    }
};
