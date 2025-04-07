class Solution {
public:
/*
bool f(int i,int sum,vector<int> &nums,vector<vector<int>> &dp,int &n)
{
    if(sum==0) return true;
    if(i==n) return false; // since if target were 0, we would not have reached this statement

    if(dp[i][sum]!=-1) return dp[i][sum];

    bool take=false;
    // take
    if(nums[i]<=sum) 
    take=f(i+1,sum-nums[i],nums,dp,n);

    bool notTake=f(i+1,sum,nums,dp,n); // not take

    return dp[i][sum]=take | notTake;
}
    bool canPartition(vector<int>& nums) {
        int totSum=0;
        for(auto it:nums)
        totSum+=it;

        if(totSum%2) return false; // odd totSum can't be halved in integer division
        int target=totSum/2,n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1, -1));

        return f(0,target,nums,dp,n);
    }*/

    bool canPartition(vector<int>& nums) {
        int totSum=0;
        for(auto it:nums)
        totSum+=it;

        if(totSum%2) return false; // odd totSum can't be halved in integer division
        int target=totSum/2,n=nums.size();
        vector<bool> prev(target+1,false),cur(target+1,false);

        prev[0]=cur[0]=true;

        for(int i=n-1;i>=0;i--)
        {
            for(int sum=1;sum<=target;sum++)
            {
                bool take=false;
                // take
                if(nums[i]<=sum) 
                take=prev[sum-nums[i]];

                bool notTake=prev[sum]; // not take

                cur[sum]=take | notTake;
            }
            prev=cur;
        }

        return prev[target];
    }
};