class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize!=0)return false;
map<int,int>mpp;
for(int num:hand){
    mpp[num]++;
}
while(!mpp.empty()){
    int curr=mpp.begin()->first;
    for(int i=0;i<groupSize;i++){
        if(mpp[curr+i]==0)return false;//not found
        if(mpp.find(curr+i)!=mpp.end()){
            mpp[curr+i]--;
            if(mpp[curr+i]<1)mpp.erase(curr+i);
        }
    }
}
return true;
    }
};
