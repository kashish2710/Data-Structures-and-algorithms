class Solution {
public:

//neg is 0
int f(int i,int j,string word1,string word2,vector<vector<int>>& dp){

    if(i>=word1.size())return word2.size()-j;
    if(j>=word2.size())return word1.size()-i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(word1[i]==word2[j])return f(i+1,j+1,word1,word2,dp);
    //does not matter if it is onsert replce or delete , just add 1.
    return dp[i][j]= 1+ min(f(i+1,j,word1,word2,dp),min(f(i,j+1,word1,word2,dp),f(i+1,j+1,word1,word2,dp)));
}
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(0,0,word1,word2,dp);
    }
};
