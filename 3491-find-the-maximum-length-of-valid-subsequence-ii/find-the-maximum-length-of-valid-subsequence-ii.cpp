class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size(),maxi=0;
        vector<vector<int>> dp(k,vector<int>(k,0));

        for(auto it:nums)
        {
            int cur=it%k;

            for(int prev=0;prev<k;prev++)
            {
                // dp[cur][prev]=len of longest valid subsequence ending with mod val=cur,
                // whose previous element is prev
                dp[cur][prev]=max(dp[cur][prev],dp[prev][cur]+1);
                maxi=max(maxi,dp[cur][prev]);
            }
        }

        return maxi;
    }
};