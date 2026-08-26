class Solution {
public:

void toposort(vector<vector<int>>& adj,vector<int>& topo,vector<int>& present){
    vector<int>indegree(26,0);
 for(auto it : adj) {
            for(int num : it) {
                indegree[num]++;
            }
        }
        queue<int>q;
        for(int i=0;i<26;i++){
            if(present[i] && indegree[i]==0)q.push(i);
        }
while(!q.empty()){
    int node=q.front();
    q.pop();
    topo.push_back(node);
    for(int num:adj[node]){
        indegree[num]--;
        if(indegree[num]==0)q.push(num);
    }
    }
}

    string foreignDictionary(vector<string>& words) {
       int n=words.size();
       string ans="";

       vector<int>present(26,0);

       for(string& word:words){
        for(int i=0;i<word.size();i++){
            present[word[i]-'a']=1;
        }
       }
vector<vector<int>>adj(26);
       for(int i=0;i<n-1;i++){
        string s1=words[i];
        string s2=words[i+1];
        int len=min(s1.size(),s2.size());
        if(s1.size()>s2.size() && s1.substr(0,len)==s2)return "";
        for(int i=0;i<len;i++){
            if(s1[i]!=s2[i]){
                adj[s1[i]-'a'].push_back(s2[i]-'a');
                break;
            }
        }
       }
       int total=0;
       for(int num:present){
        if(num==1)total++;
       }
       vector<int>topo;
       toposort(adj,topo,present);
       if(topo.size()!=total)return "";
       for(int num:topo){
        ans+=char(num+'a');
       }
return ans;
    }
};
