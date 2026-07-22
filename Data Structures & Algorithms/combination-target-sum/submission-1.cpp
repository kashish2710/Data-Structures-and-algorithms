class Solution {
public:
void solve(int idx,vector<int>& nums,int target,vector<vector<int>>&ans,vector<int>&ds){
   if(idx>=nums.size())return;
   if(target==0){
    ans.push_back(ds);
    return;
   }
   
   if(nums[idx]<=target){
    ds.push_back(nums[idx]);
    solve(idx,nums,target-nums[idx],ans,ds);
    ds.pop_back();
   }
   solve(idx+1,nums,target,ans,ds);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,nums,target,ans,ds);
        return ans;
    }
};
