class Solution {
public:
bool f(int i,int target,vector<int> &nums,vector<vector<int>> &dp,int &n)
{
    if(target==0) return true;
    if(i==n) return false; // since if target were 0, we would not have reached this statement

    if(dp[i][target]!=-1) return dp[i][target];
    
    bool take=false;
    // take
    if(nums[i]<=target) 
    take=f(i+1,target-nums[i],nums,dp,n);

    bool notTake=f(i+1,target,nums,dp,n); // not take

    return dp[i][target]=take | notTake;
}
    bool canPartition(vector<int>& nums) {
        int totSum=0;
        for(auto it:nums)
        totSum+=it;

        if(totSum%2) return false; // odd totSum can't be halved in integer division
        int target=totSum/2,n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1, -1));

        return f(0,target,nums,dp,n);
    }
};