class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>myset(nums.begin(),nums.end());
        int maxi=0;
        int len=0;
        for(int num:nums){
          if(myset.find(num-1)==myset.end()){//this could be possible starting of the new sequence
              len=1;
              while(myset.find(num+1)!=myset.end()){
                len++;
                num=num+1;
              }
             maxi=max(maxi,len);
            }
             
        }   
        
        
        return maxi;
    }
};
