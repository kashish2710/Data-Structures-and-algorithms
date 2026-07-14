class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
int total=m*n;
int expected=total*(total+1)/2;
unordered_map<int,int>mpp;
vector<int>ans;
int actual=0;
int missing;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

             if(mpp[grid[i][j]]>=1){
                missing =grid[i][j];
                ans.push_back(missing);
                }
           
                actual+=grid[i][j];
            
          mpp[grid[i][j]]++;
            }
        }
        actual-=missing;
ans.push_back(expected-actual);
return ans;
    }
};