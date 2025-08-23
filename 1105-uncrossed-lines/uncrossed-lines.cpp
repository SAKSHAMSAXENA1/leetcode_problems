class Solution {
public:
/* // Memoization
int f(int i,int farthest,vector<int> &nums1,unordered_map<int,vector<int>> &indicesNums2,int &m
,vector<vector<int>> &dp)
{
    if(i==m) return 0;

    if(dp[i][farthest]!=-1) return dp[i][farthest];

    int take=0;

    for(auto it:indicesNums2[nums1[i]])
    {
        if(it>farthest)
        {
            take=max(take,1+f(i+1,it,nums1,indicesNums2,m,dp));
        }
    }

    int notTake=f(i+1,farthest,nums1,indicesNums2,m,dp);

    return dp[i][farthest]=max(take,notTake);
}
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,vector<int>> indicesNums2;
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        for(int i=0;i<n;i++)
        {
            indicesNums2[nums2[i]].push_back(i+1);
        }

        return f(0,0,nums1,indicesNums2,m,dp);
    }*/

// Tabulation
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,vector<int>> indicesNums2;
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+2,0));

        for(int i=0;i<n;i++)
        {
            indicesNums2[nums2[i]].push_back(i+1);
        }

        for(int i=m-1;i>=0;i--)
        {
            for(int farthest=n;farthest>=0;farthest--)
            {
                int take=0;

                for(auto it:indicesNums2[nums1[i]])
                {
                    if(it>farthest)
                    {
                        take=max(take,1+dp[i+1][it]);
                    }
                }

                int notTake=dp[i+1][farthest];

                dp[i][farthest]=max(take,notTake);
            }
        }

        return dp[0][0];
    }

};