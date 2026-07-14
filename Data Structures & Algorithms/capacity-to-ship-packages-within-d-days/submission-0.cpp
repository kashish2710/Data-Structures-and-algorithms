class Solution {
public:

bool check(int capacity, vector<int>& weights, int days){
    int day=1;
    int initial=capacity;
    for(int i=0;i<weights.size();i++){
        if(weights[i]<=capacity){
            capacity=capacity-weights[i];    
        }
      else {
        day++;
        capacity=initial;
         capacity -= weights[i];   
        if(day>days){
            return false;
        }
      }

    }
    return true;

}
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0;
        for(int weight:weights){
            high+=weight;
        }
        int low=*max_element(weights.begin(),weights.end());
        int ans=0;
while(low<=high){
    int mid=(high+low)/2;
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