class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>result;
        vector<int>hash(26,0);
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']=i;
        }
        int i=0;
        while(i<s.size()){
            int end=hash[s[i]-'a'];
            int j=i;
            while(j<end){
end=max(end,hash[s[j]-'a']);
j++;
            }
            int ans=j-i+1;
            result.push_back(ans);
            i=end+1;
        }
        return result;
    }
};
