class Solution {    
public:
bool ispalindrome(int i,int j,string& s,vector<vector<int>>& dp){
if(i>=j)return true;
if(dp[i][j]!=-1)return dp[i][j];
if(s[i]==s[j])return dp[i][j]=ispalindrome(i+1,j-1,s,dp);
return dp[i][j]=false;
}
    int countSubstrings(string s) {
        int count=0;
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size(),-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
if(ispalindrome(i,j,s,dp)){count++;}
        }
        }
        return count;
    }
};
