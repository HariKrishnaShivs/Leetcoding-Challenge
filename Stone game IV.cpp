class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                dp[i]=dp[i]||(!dp[i-j*j]);
            }
        }
        return dp[n];
    }
};