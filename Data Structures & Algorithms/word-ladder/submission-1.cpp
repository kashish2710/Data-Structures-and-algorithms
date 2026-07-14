class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>myset(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
          string word=q.front().first;
          int level=q.front().second;
          q.pop();
        if(word==endWord)return level;
          for(int i=0;i<word.size();i++){
            char ch=word[i];
            for(char ch='a';ch<='z';ch++){
              word[i]=ch;
              if(myset.find(word)!=myset.end()){
                   q.push({word,level+1});
                   myset.erase(word);
              }
            }
            word[i]=ch;
          }
        }
return 0;
    }
};
