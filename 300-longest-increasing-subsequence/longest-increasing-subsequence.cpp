class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),maxi=1;
        vector<int> dp(n,1);

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp[j]+1>dp[i])
                    dp[i]=dp[j]+1;
            }

            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};