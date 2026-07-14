class Solution {
public:
void combination(int idx,string digits,vector<string>& mp,string& word,vector<string>& ans){
    if(idx==digits.size()){
        ans.push_back(word);
        return;
    }
    int digit=digits[idx]-'0';
    string mapped=mp[digit];

    for(int i=0;i<mapped.size();i++){
        word.push_back(mapped[i]);
        combination(idx+1,digits,mp,word,ans);
        word.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
      vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string>ans;
string word="";
if(digits=="")return ans;
combination(0,digits,mp,word,ans);
return ans;
    }
};
