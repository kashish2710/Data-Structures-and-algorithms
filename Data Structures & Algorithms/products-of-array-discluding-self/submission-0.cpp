class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
vector<int>prefix(n+1,1);
vector<int>suffix(n,1);
for(int i=1;i<=nums.size();i++){
    prefix[i]=prefix[i-1]*nums[i-1];
}
for(int i=n-1;i>0;i--){
    suffix[i-1]=suffix[i]*nums[i];

}
suffix.push_back(1);
vector<int>ans;
for(int i=0;i<n;i++){
    ans.push_back(suffix[i]*prefix[i]);
}
return ans;
    }
};
