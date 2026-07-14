class Solution {
public:
    bool isPalindrome(string s) {
       
        
        string new_s="";
        for(char ch:s){
            if(isalpha(ch) || isdigit(ch)){
                new_s+=tolower(ch);
            }
        }
        int i=0;
        int j=new_s.size()-1;
         int n=new_s.size();
        while(i<n/2){
            if(new_s[i]!=new_s[j])return false;
            i++;
            j--;
        }
        return true;
    }
};
