#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
           return 0;
        vector<int> dp(n);
        dp[0]=nums[0];
        if(n==1)
          return dp[0];
        dp[1]=max(nums[0],nums[1]);
        if(n==2)
            return dp[1];
        if(n==3)
            return max(dp[1],nums[2]);
        for(int i=2;i<n-1;i++)
        {
            dp[i]=dp[i-1];
            for(int j=0;j<=i-2;j++)
            {
                dp[i]=max(dp[i],nums[i]+dp[j]);
            }
        }
        int maxval=dp[0];
        for(int i=1;i<n;i++)
        {
            maxval=max(maxval,dp[i]);
        }
        vector<int> dp1(n);
        dp1[1]=nums[1];
        dp1[2]=max(nums[1],nums[2]);
        for(int i=3;i<n;i++)
        {
             dp1[i]=dp1[i-1];
            for(int j=1;j<=i-2;j++)
            {
                dp1[i]=max(dp1[i],nums[i]+dp1[j]);
            }
        }
        maxval=max(maxval,dp1[n-1]);
        return maxval;
    }
};