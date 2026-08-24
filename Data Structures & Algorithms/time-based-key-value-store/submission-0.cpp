class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<int,string>>>mpp;
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end())return "";
        int low=0;
        string ans="";
        int high=mpp[key].size()-1;
        if(mpp[key][0].first>timestamp){
            return "";
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mpp[key][mid].first==timestamp){
                return mpp[key][mid].second;
            }
            else if(mpp[key][mid].first<timestamp){
                ans=mpp[key][mid].second;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};
