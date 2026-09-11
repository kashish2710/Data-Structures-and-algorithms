class Solution {
public:
void sum(int idx,vector<int>& nums,int target,vector<int>& ds,vector<vector<int>>& ans){
if(idx>=nums.size()){
if(target==0){
    ans.push_back(ds);
    }
    return;

}

if(nums[idx]<=target){
    ds.push_back(nums[idx]);
    sum(idx,nums,target-nums[idx],ds,ans);
    ds.pop_back();
}
sum(idx+1,nums,target,ds,ans);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
sum(0,nums,target,ds,ans);
return ans;
    }
};
