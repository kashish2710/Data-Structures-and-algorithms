class Solution {
public:
int atmostk(vector<int>& nums, int k){
    unordered_map<int,int>mpp;
    int left=0;
    int right=0;
    int n=nums.size();
    int count=0;
    while(right<n){
        mpp[nums[right]]++;
        while(mpp.size()>k){
    mpp[nums[left]]--;
    if(mpp[nums[left]]==0)mpp.erase(nums[left]);
    left++;
}
count+=right-left+1;
        right++;
    }
    return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums,k)-atmostk(nums,k-1);


    }
};