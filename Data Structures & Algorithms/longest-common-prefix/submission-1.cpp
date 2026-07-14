class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string word=strs[0];// let this is the common word only
        for(int i=1;i<n;i++){
              if(strs[i]=="")return "";
            for(int j=0;j<strs[i].size();j++){
              
                if(j > word.size() || strs[i][j]!=word[j]){
                    word=word.substr(0,j);
                    break;
                }
                if(strs[i].size() < word.size()){
                    word=word.substr(0,strs[i].size());
                }
                if(word.empty())return "";
            }
        }
        return word;

    }
};