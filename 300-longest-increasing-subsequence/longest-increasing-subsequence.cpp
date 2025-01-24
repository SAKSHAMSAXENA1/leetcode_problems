class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),res=1;
        vector<int> dp(n,1);

        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                }
            }

            res=max(res,dp[i]);
        }

        return res;
    }
};