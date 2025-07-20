class Solution {
public:
bool f(int index,vector<int> &nums,vector<int> &dp,int &n)
{
    if(index==n-1) return true;

    if(nums[index]==0) return false;

    if(dp[index]!=-1) return dp[index];

    for(int jump=1;jump<=nums[index] && index+jump<n;jump++)
    {
        if(f(index+jump,nums,dp,n)==true) return true;
    }

    return dp[index]=false;
}
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp,n);
    }
};