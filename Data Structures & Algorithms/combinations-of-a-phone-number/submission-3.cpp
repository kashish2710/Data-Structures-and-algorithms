class Solution {
public:
void solve(int idx,string& digits,vector<string>& letter,vector<string>& ans,string& ds){
    if(idx>=digits.size()){
        ans.push_back(ds);
        return;
    }
    int digit=digits[idx]-'0';
    string mapped=letter[digit];
   for(int i=0;i<mapped.size();i++){
    ds.push_back(mapped[i]);
    solve(idx+1,digits,letter,ans,ds);
    ds.pop_back();
   }
}
    vector<string> letterCombinations(string digits) {
        vector<string>letter={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       vector<string>ans;
       string ds;
        if(digits=="")return ans;
       solve(0,digits,letter,ans,ds);
       return ans;

    }
};
