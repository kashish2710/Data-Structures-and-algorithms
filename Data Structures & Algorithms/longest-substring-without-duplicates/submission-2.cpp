class Solution {
public:
    int lengthOfLongestSubstring(string s) {
int n=s.size();
        vector<int>hash(256,-1);
        int left=0;
        int right=0;
        int maxi=0;
        while(right<n){
            // already seen
          if(hash[s[right]]!=-1){
               if(hash[s[right]]>=left){
                left=hash[s[right]]+1;
               }
          }
          hash[s[right]]=right;
          maxi=max(right-left+1,maxi);
          right++;
        }
return maxi;
    }
};
