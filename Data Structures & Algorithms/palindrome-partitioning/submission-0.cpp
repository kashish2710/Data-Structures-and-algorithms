class Solution {
public:
bool isPalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
void func(int idx,vector<string> curr,string s,vector<vector<string>>& ans){
if(idx==s.size()){
    ans.push_back(curr);
    return;
}
for(int i=idx;i<s.size();i++){
    if(isPalindrome(idx,i,s)){
        curr.push_back(s.substr(idx,i-idx+1));
        func(i+1,curr,s,ans);
        curr.pop_back();
    }
}
}


    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> curr;
         func(0,curr,s,ans);
         return ans;


    }
};
