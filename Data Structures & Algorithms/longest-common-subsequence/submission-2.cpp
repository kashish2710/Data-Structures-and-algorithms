class Solution {
public:
int LCS(int idx1, int idx2, string text1, string text2,vector<vector<int>>&dp){
    if(idx1==text1.size() || idx2==text2.size())return 0;
    if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
    if(text1[idx1]==text2[idx2])return 1 + LCS(idx1+1,idx2+1,text1,text2,dp);
    return dp[idx1][idx2]=max(LCS(idx1+1,idx2,text1,text2,dp),LCS(idx1,idx2+1,text1,text2,dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        //Tabulation
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int idx1=1; idx1<=n1; idx1++){

            for(int idx2=1; idx2<=n2; idx2++){

               if(text1[idx1-1]==text2[idx2-1])dp[idx1][idx2]= 1 + dp[idx1-1][idx2-1];
            else dp[idx1][idx2]=max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
 
            }
        }

return dp[n1 ][n2];
        // return LCS(0,0,text1,text2,dp);
    }
};
