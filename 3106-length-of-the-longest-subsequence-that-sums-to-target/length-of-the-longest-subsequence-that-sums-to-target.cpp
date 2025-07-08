class Solution {
public:
int f(int index,int rem,vector<int> &nums,int &n,vector<vector<int>> &dp)
{
    if(rem==0) return 0;

    if(index==n) // && rem!=0
    return INT_MIN;

    if(dp[index][rem]!=-1) return dp[index][rem];

    // take
    int take=INT_MIN;
    if(nums[index]<=rem)
    {
        int temp=f(index+1,rem-nums[index],nums,n,dp);
        if(temp!=INT_MIN) take=1+temp;
    }
    

    // not take
    int notTake=f(index+1,rem,nums,n,dp);

    return dp[index][rem]=max(take,notTake);
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int res=f(0,target,nums,n,dp);
        if(res==INT_MIN) return -1;
        return res;
    }
};