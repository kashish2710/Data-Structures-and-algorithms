class Solution {
public:
void permutation(vector<int>& nums,vector<int>&ds,vector<vector<int>>& ans, vector<int>&taken){
if(ds.size()==nums.size()){
    ans.push_back(ds);
    return;
}
for(int i=0;i<nums.size();i++){
    if(!taken[i]){
        taken[i]=1;
        ds.push_back(nums[i]);
       permutation(nums,ds,ans,taken);
        ds.pop_back();
        taken[i]=0;
    }
}
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>taken(n,0);
        vector<int>ds;
       permutation(nums,ds,ans,taken);
        return ans;
    }
};
