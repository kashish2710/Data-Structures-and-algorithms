class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>myset(nums.begin(),nums.end());
        int maxlen=0;
        for(int num:nums){
            if(myset.find(num-1)==myset.end()){
                int len=0;
                while(myset.find(num)!=myset.end()){
                    len++;
                    num=num+1;
                    maxlen=max(maxlen,len);
                }
            }
        }
        return maxlen;
    }
};
