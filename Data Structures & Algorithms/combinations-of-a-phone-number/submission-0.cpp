class Solution {
public:
void combination(int idx, vector<string>& ans,string output,string digits, vector<string>& letter){
    if(idx>=digits.size()){
        ans.push_back(output);
        return;
    }
    int num=digits[idx]-'0';
    string s=letter[num];
    for(int i=0;i<s.size();i++){
        output.push_back(s[i]);
        combination(idx+1,ans,output,digits,letter);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
     vector<string>letter={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     vector<string>ans;
     string output="";
if(digits=="")return {};
     combination(0,ans,output,digits,letter);
     return ans;
    }
};
