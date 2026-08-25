class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            while(j<word.size() && j<strs[i].size() && word[j]==strs[i][j]){
                j++;
            }
            word=word.substr(0,j);
            if(word.empty())return "";
        }
        return word;
    }
};