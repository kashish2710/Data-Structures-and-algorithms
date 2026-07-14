class Solution {
public:
    int solve(int i, int j, int prev,
              vector<vector<int>>& matrix,
              vector<vector<int>>& dp,
              int m, int n) {

        if(i < 0 || i >= m || j < 0 || j >= n ||
           matrix[i][j] <= prev)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = 1 + max({
            solve(i + 1, j, matrix[i][j], matrix, dp, m, n),
            solve(i - 1, j, matrix[i][j], matrix, dp, m, n),
            solve(i, j + 1, matrix[i][j], matrix, dp, m, n),
            solve(i, j - 1, matrix[i][j], matrix, dp, m, n)
        });
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int maxi = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                maxi = max(maxi,
                           solve(i, j, INT_MIN,
                                 matrix, dp, m, n));
            }
        }

        return maxi;
    }
};