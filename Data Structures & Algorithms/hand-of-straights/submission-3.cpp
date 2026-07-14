class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mpp;
        for(int num:hand){
            mpp[num]++;
        }
        while(!mpp.empty()){
            auto num=mpp.begin();
            int curr=num->first;
            for(int i=0;i<groupSize;i++){
                if(mpp.find(curr+i)==mpp.end()){
return false;
                }
                mpp[curr+i]--;
            if(mpp[curr+i]==0)mpp.erase(curr+i);
            }
}
return true;
        
    }
};
