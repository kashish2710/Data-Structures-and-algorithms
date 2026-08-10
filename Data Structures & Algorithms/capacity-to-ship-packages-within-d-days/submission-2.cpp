class Solution {
public:
bool check(int capacity,vector<int>& weights, int days){
int day=1;
int original=capacity;

for(int weight:weights){
    if(weight<=capacity){
     capacity-=weight;
    }
    else{
 day++;
 capacity=original;
  capacity-=weight;
    }
   

}
if(day<=days)return true;
return false;
}
    int shipWithinDays(vector<int>& weights, int days) {
      int low=*max_element(weights.begin(),weights.end());
      int high=accumulate(weights.begin(),weights.end(),0);
      int ans=0;
      while(low<=high){
        int mid=low+(high-low)/2;
        if(check(mid,weights,days)){
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