class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int i=0;
        int j=0;
        unordered_map<char,int>mpp;
        for(char ch:t){
            mpp[ch]++;
        }
        int require=t.size();
        string ans="";
        int window=INT_MAX;
    int start=i;
    while(j<n){
        char ch=s[j];
        if(mpp[ch]>0){
            require--;
        }
        mpp[ch]--;
        while(require==0){
            if(window>j-i+1){
                window=j-i+1;
                start=i;
            }
            mpp[s[i]]++;
            if(mpp[s[i]]>0){
                require++;
            }
           
            i++;
        }
        j++;
    }
    return window==INT_MAX ? "":s.substr(start,window);
    }
};
