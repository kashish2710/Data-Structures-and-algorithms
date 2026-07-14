class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;//a-z A- Z @#$%^&*
        int n=s.size();
        int maxi=0;
        vector<int>hash(256,-1);
        while(right<n){
            if(hash[s[right]]!=-1){//already seen
            if(hash[s[right]]>=left)//in the window
               left=hash[s[right]]+1;


            }
            hash[s[right]]=right;
            maxi=max(maxi,right-left+1);
            right++;


        }
        return maxi;
    }
};
