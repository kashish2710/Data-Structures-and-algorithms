class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size();
        int left=0;
        int right=0;
        int k=s1.size();
        vector<int>hash(26,0);
        for(int i=0;i<k;i++){
            hash[s1[i]-'a']++;
        }
        vector<int>s2freq(26,0);
        while(right<n){
          s2freq[s2[right]-'a']++;
          if(right-left+1 > k){
            s2freq[s2[left]-'a']--;
            left++;
          }
          if(hash==s2freq)return true;
right++;
        }
        return false;
    }
};
