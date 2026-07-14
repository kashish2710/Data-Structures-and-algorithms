class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        int window=INT_MAX;
        int start_idx=0;
        for(char ch:t){
            mpp[ch]++;
        }
        int require=t.size();

        int left=0;
        int right=0;
        int n=s.size();
        while(right < n){
         char ch=s[right];
         if(mpp[ch]>0){
            require--;
         }
         mpp[ch]--;
        while(require==0){
          if(window > right-left+1){
             window=right-left+1;
             start_idx=left;
             }
             mpp[s[left]]++;
             if(mpp[s[left]]>0){
                require++;
             }
             left++;
             

        }
        right++;

        }
return window==INT_MAX ? "" : s.substr(start_idx,window);
    }
};
