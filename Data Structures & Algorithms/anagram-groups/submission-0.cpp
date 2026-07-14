class Solution {
public:

string generate(string word){
  vector<int>freq(26,0);
    string new_word="";
    for(char ch:word){
        freq[ch-'a']++;
    }
    for(int i=0;i<freq.size();i++){
        int frequency=freq[i];
        if(frequency>0){
          new_word+=string(frequency,i+'a');
        }
       
    }
    return new_word;
}


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(string s:strs){
          string new_word=generate(s);
          mpp[new_word].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto it:mpp){
ans.push_back(it.second);
        }
        return ans;
    }
};
