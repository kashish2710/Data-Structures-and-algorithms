class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]=i;
        }
        vector<int>ans;
        int i=0;
        while(i<s.size()){
            int end=mpp[s[i]];
            for(int j=i;j<end;j++){
                end=max(end,mpp[s[j]]);
            }
            ans.push_back(end-i+1);
            i=end+1;
        }
        return ans;
    }
};
