class Solution {
public:
int solve(int idx,vector<int>& nums,int target){
    if(idx==nums.size()){
        if(target==0)return 1;
        return 0;
    }
    int skip=solve(idx+1,nums,target);
    int pick=0;
    if(target>=nums[idx]){
        pick=solve(idx+1,nums,target-nums[idx]);
    }
    return pick+ skip;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total-target<0 || (total-target) % 2)return 0;
         int ntarget=(total-target)/2;
         return solve(0,nums,ntarget);
    }
};
