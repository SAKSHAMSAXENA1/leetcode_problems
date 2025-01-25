class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxi=0,res=0;
        vector<int> dp(n,1),cnt(n,1);

        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]>nums[prev] && dp[prev]+1>dp[i])
                {
                    dp[i]=dp[prev]+1;
                    cnt[i]=cnt[prev];
                }
                else if(nums[i]>nums[prev] && dp[i]==dp[prev]+1)
                {
                    cnt[i]+=cnt[prev];
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                res=cnt[i];
            }
            else if(dp[i]==maxi) res+=cnt[i];
        }

        return res;
    }
};