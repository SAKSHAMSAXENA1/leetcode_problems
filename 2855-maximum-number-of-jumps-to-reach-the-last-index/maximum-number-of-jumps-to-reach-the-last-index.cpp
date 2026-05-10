class Solution {
public:
int f(int i,vector<int> &nums,int &target,int &n, vector<int> &dp)
{
    if(i==n-1) return 0;

    if(dp[i] != -1) return dp[i];
    
    int res = INT_MIN;
    for(int j=i+1;j<n;j++)
    {
        int temp = INT_MIN;
        if(abs(nums[j]-nums[i]) <= target)
        temp = f(j,nums,target,n,dp);

        if(temp != INT_MIN)
        res = max(res, 1 + temp);
    }

    return dp[i] = res;
}
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n,-1);

        int res = f(0,nums,target,n,dp);

        return res == INT_MIN ? -1 : res;
    }
};