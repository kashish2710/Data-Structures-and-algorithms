class Solution {
public:
int f(int idx,vector<int>& nums,int target){
   if(idx==0){
    if(target==0 && nums[idx]==0)return 2;
    if(target==0 || nums[idx]==target)return 1;
    return 0;
   }
   int skip=f(idx-1,nums,target);
   int pick=0;
   if(nums[idx]<=target){
    pick=f(idx-1,nums,target-nums[idx]);
   }
   return pick + skip;
   }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
    for(int num:nums){
        sum+=num;
    }
     if(sum-target<0  || (sum-target) % 2) return 0;
    int ntarget=(sum-target)/2;
   
        return f(nums.size()-1,nums,ntarget);
    }
};
