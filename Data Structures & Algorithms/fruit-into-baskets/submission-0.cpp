class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      unordered_map<int,int>mpp;
      int left=0;
      int right=0;
      int n=fruits.size();
      int maxi=0;

      while(right<n){
        mpp[fruits[right]]++;
        if(mpp.size()>2){
            mpp[fruits[left]]--;
            if(mpp[fruits[left]]==0)mpp.erase(fruits[left]);
            left++;
        }
        maxi=max(right-left+1,maxi);

right++;
      } 
      return maxi;
    }
};