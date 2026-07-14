class Solution {
public:
void subset(int idx,vector<int>& nums,vector<int> &ds,vector<vector<int>> &ans){
if(idx==nums.size()){
    ans.push_back(ds);
    return;
}

ds.push_back(nums[idx]);
subset(idx+1,nums,ds,ans);
ds.pop_back();
subset(idx+1,nums,ds,ans);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        subset(0,nums,ds,ans);
return ans;
    }
};
