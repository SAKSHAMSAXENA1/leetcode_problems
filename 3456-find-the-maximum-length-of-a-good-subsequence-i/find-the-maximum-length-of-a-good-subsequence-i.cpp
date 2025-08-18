class Solution {
public:
/*
// Memoization
int f(int index,int prev,int remK,vector<int> &nums,int &n,vector<vector<vector<int>>> &dp)
{
    if(index==n+1) return 0;

    if(dp[index][prev][remK]!=-1) return dp[index][prev][remK];

    int take=INT_MIN,notTake=INT_MIN;

    // take
    if(prev==0 || nums[prev-1]==nums[index-1])
    take=1+f(index+1,index,remK,nums,n,dp);
    else if(remK>0)
    take=1+f(index+1,index,remK-1,nums,n,dp);

    // notTake
    notTake=f(index+1,prev,remK,nums,n,dp);

    return dp[index][prev][remK]=max(take,notTake);
}
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return f(1,0,k,nums,n,dp);
    }*/

// Tabulation
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n+2,vector<vector<int>>(n+1,vector<int>(k+1,0)));

        for(int index=n;index>=1;index--)
        {
            for(int prev=index-1;prev>=0;prev--)
            {
                for(int remK=0;remK<=k;remK++)
                {
                    int take=INT_MIN,notTake=INT_MIN;

                    // take
                    if(prev==0 || nums[prev-1]==nums[index-1])
                    take=1+dp[index+1][index][remK];
                    else if(remK>0)
                    take=1+dp[index+1][index][remK-1];

                    // notTake
                    notTake=dp[index+1][prev][remK];

                    dp[index][prev][remK]=max(take,notTake);
                }
            }
        }
        return dp[1][0][k];
    }
};