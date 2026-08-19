class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize !=0)return false;
        map<int,int>mpp;
        //stores freq
        for(int num:hand){
            mpp[num]++;
        }
        while(!mpp.empty()){
            int node=mpp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mpp.find(node)==mpp.end()){
                return false;
                }
                mpp[node]--;
                if(mpp[node]==0)mpp.erase(node);
                node=node+1;
            }
        }
return true;
    }
};
