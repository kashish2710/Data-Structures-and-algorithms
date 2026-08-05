class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize!=0)return false;
        map<int,int>mpp;
        for(int num:hand){
            mpp[num]++;
        }
        while(!mpp.empty()){
           auto it=mpp.begin();
            int num=it->first;
           
            for(int i=0;i<groupSize;i++){
            if(mpp.find(num+i)==mpp.end()){
                return false;
            }
            mpp[num+i]--;
            if(mpp[num+i]==0)mpp.erase(num+i);
            }
        }
        return true;
    }
};
