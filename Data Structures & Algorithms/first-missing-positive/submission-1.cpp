class Solution {
public:
//inclusive [1,n]
    int firstMissingPositive(vector<int>& nums) {
        bool contains1=false;
       for(int i=0;i<nums.size();i++){
        
    if(nums[i]==1) contains1=true;
if(nums[i]<=0 || nums[i]>nums.size())//invalid index
        nums[i]=1;
    
}
        if(contains1==false)return 1;

        for(int i=0;i<nums.size();i++){
            int num=abs(nums[i]);
            int idx=num-1;
        
            if(nums[idx]<0)continue;
                nums[idx]*=-1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};