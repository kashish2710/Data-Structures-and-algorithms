class Solution {
public:
int f(int i,int j,string text1,string text2){
    if(i<0 || j<0)return 0;
    if(text1[i]==text2[j]) return 1+ f(i-1,j-1,text1,text2);
    return max(f(i-1,j,text1,text2),f(i,j-1,text1,text2));
}
    int longestCommonSubsequence(string text1, string text2) {
int m=text1.size();
int n=text2.size();
vector<vector<int>>dp(m+1,vector<int>(n+1,0));
for(int i=0;i<m;i++){
    dp[i][0]=0;
}
for(int i=0;i<n;i++){
    dp[0][i]=0;
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(text1[i-1]==text2[j-1]){ dp[i][j]=1+dp[i-1][j-1];}
       else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}
return dp[m][n];
        // return f(m-1,n-1,text1,text2,dp);
    }
};
