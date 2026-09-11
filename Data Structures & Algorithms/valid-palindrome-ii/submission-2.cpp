class Solution {
public:
bool isvalid(int i,int j,string s){

        if(i>j)return true;
        if(s[i]!=s[j])return false;
        return isvalid(i+1,j-1,s);
    
}
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
           else  if(s[i]!=s[j]){
                return isvalid(i+1,j,s) || isvalid(i,j-1,s);
            }
        }
        return true;
    }
};