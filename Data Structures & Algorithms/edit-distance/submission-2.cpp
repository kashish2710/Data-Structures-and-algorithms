class Solution {
public:
int solve(int i,int j,string& word1,string& word2){
    if(j<0)return i+1;
    if(i<0)return j+1;
    if(word1[i]==word2[j]){
  return  solve(i-1,j-1,word1,word2);
}
    
    return 1+min(solve(i-1,j,word1,word2),min(solve(i,j-1,word1,word2),solve(i-1,j-1,word1,word2)));

}
    int minDistance(string word1, string word2) {
          int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i = 0; i <= m; i++)
    dp[i][0] = i;

for(int j = 0; j <= n; j++)
    dp[0][j] = j;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
        // return solve(m-1,n-1,word1,word2);
    }
};
