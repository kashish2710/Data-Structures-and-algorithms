class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
      int ans=0;
      int i=0;
      while(i<n){
        char ch=chars[i];
        int j=i;
        while(j<n && chars[j]==ch){
            j++;
        }
        chars[ans++]=ch;
        int count=j-i;
        if(count>1){
            string s=to_string(count);
            for(char c:s){
                chars[ans++]=c;
            }
          
        }
        i=j;
      }
      return ans;
    }
};