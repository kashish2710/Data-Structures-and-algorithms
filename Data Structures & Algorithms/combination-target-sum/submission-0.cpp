class Solution {
public:
void combination(int idx,vector<int>& nums, int target,vector<int>& ds,vector<vector<int>>& ans){
if(idx==nums.size()){
    if(target==0){
        ans.push_back(ds);
        }
    return;
}
//if pick
if(nums[idx]<=target){
    ds.push_back(nums[idx]);
combination(idx,nums,target-nums[idx],ds,ans);
ds.pop_back();
}

//if not pick
combination(idx+1,nums,target,ds,ans);


}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        combination(0,nums,target,ds,ans);
        return ans;
    }
};
