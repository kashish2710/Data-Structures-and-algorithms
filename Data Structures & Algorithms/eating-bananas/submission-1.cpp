class Solution {
public:

bool canEat(int banana,vector<int>& piles,int h ){
    int hours=0;
    for(int pile:piles){
    hours+=(pile + banana - 1) / banana;
    }
    if(hours<=h)return true;
    return false;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(canEat(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
