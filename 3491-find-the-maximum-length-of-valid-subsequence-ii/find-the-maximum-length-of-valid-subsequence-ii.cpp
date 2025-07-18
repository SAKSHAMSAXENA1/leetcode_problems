class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size(),maxi=0;
        vector<vector<int>> dp(k,vector<int>(n,1));

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int mod=(nums[j]+nums[i])%k;
                dp[mod][i]=max(dp[mod][i],dp[mod][j]+1);
                maxi=max(maxi,dp[mod][i]);
            }
        }

        return maxi;
    }
};