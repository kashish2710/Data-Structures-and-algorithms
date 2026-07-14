class Solution {
public:
    vector<int> partitionLabels(string s) {
       vector<int>result;
        vector<int>hash(26,0);
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']=i;
        }
        int start=0;
        int end=0;
        int i=0;
        while(i<s.size()){
            end=max(end,hash[s[i]-'a']);
            if(i==end){
                result.push_back(end-start+1);
                start=i+1;
             }
i++;

        }  
        return result;
    }
};
