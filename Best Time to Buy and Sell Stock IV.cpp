class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
         if (k * 2 >= prices.size())
        {
            int s = 0; 

            for (int i = 1; i < prices.size(); i++)
            {
                int x = prices[i] - prices[i - 1];

                if (x >= 0)
                {
                    s += x;
                }
            }

            return s;
        }
        
       int n=prices.size();
        if((n==0)||(n==1))
            return 0;
        vector<vector<int> > dp(n+1,vector<int> (k+1,0) );
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                int maxval=INT_MIN;
                for(int l=i-1;l>=0;l--)
                {
                    maxval=max(maxval,prices[i]-prices[l]+dp[l][j-1]);
                }
                dp[i][j]=max(maxval,dp[i-1][j]);
            }
        }
        return dp[n-1][k];
    }
};