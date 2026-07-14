class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
       int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
           int  hours=0;
            for(int pile:piles){
                hours+=ceil((double)pile/mid);
            }
if(hours<=h){
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
