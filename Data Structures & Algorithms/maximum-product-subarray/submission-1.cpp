class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n=nums.size();
      int maxproduct=INT_MIN;
        
        int pre=1;
        int suf=1;
        for(int i=0;i<n;i++){

if(pre==0){
  pre=1;
}
if(suf==0){
  suf=1;
}

pre=pre* nums[i];
suf=suf*nums[n-1-i];


      maxproduct=max(maxproduct,max(pre,suf));
        }
  
return maxproduct;
    }
};
