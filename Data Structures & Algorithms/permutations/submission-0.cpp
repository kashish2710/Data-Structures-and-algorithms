class Solution {
public:
void permutation(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds,vector<int>& taken){
if(ds.size()==nums.size()) {
    ans.push_back(ds);
    return ;
}
for(int i=0;i<nums.size();i++){
    if(!taken[i]){//not taken
taken[i]=1;
ds.push_back(nums[i]);
permutation(nums,ans,ds,taken);
ds.pop_back();
taken[i]=0;
    }
}
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>taken(n,0);
        permutation(nums,ans,ds,taken);
return ans;
    }
};
