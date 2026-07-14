class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int n=s.size();
        unordered_map<char,int>mpp;  // {char,idx}
        int maxlen=0;
        while(right<n){
            if(mpp.find(s[right])!=mpp.end()){
                if(mpp[s[right]]>=left){
                    left=1+mpp[s[right]];
                }

            }
            mpp[s[right]]=right;
            maxlen=max(maxlen,right-left+1);

            right++;
        }
        return maxlen;
    }
};
