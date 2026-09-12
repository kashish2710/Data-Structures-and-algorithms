class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }

        int mask=ans & (-ans);// this will give the rightmost set bit
        int g1=0;
        int g2=0;
        for(int i=0;i<n;i++){
            if(nums[i] & mask){
                g1^=nums[i];
            }
            else{
                g2^=nums[i];
            }
        }
return {g1,g2};

    }
};