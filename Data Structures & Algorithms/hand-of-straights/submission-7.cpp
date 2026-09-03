class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize !=0)return false;
        map<int,int>mpp;
        for(int num:hand){
            mpp[num]++;
        }
       while(!mpp.empty()){
         
            int num=  mpp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mpp.find(num)==mpp.end())return false;
                 mpp[num]--;
                if(mpp[num]==0){
                    mpp.erase(num);
                }
                num=num+1;
            }
       }
            return true;
         
        
    }
};
