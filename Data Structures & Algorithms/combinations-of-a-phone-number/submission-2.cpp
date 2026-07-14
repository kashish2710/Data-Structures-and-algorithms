class Solution {
public:
    void combination(int idx,string digits,vector<string>& letters,vector<string>& result,string ans){
if(idx>digits.size()-1){
    result.push_back(ans);
    return;
}

int digit=digits[idx]-'0';
string word=letters[digit];

for(int i=0;i<word.size();i++){
    ans.push_back(word[i]);
    combination(idx+1,digits,letters,result,ans);
    ans.pop_back();

}

    }
    vector<string> letterCombinations(string digits) {
        vector<string>letters={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>result;
        string ans="";
        if(digits=="")return result;
combination(0,digits,letters,result,ans);
return  result;
    }
};
