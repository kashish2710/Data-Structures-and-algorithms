class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>myset(nums.begin(),nums.end());
        int maxlen=0;
        for(int num:nums){
int len=0;
      while(myset.find(num)!=myset.end()){
        len++;
        maxlen=max(maxlen,len);
        num=num+1;
      }
        }
        return maxlen;
    }
};
