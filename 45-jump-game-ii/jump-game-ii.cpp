class Solution {
public:
int f(int index,vector<int> &nums,vector<int> &dp,int &n)
{
    if(index==n-1) return 0;

    if(dp[index]!=-1) return dp[index];

    int mini=INT_MAX;

    for(int jumps=1;jumps<=nums[index] && index+jumps<n;jumps++)
    {
        int nextJumps=f(index+jumps,nums,dp,n);

        if(nextJumps!=INT_MAX)
        mini=min(mini,1+nextJumps);
    }

    return dp[index]=mini;
}
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp,n);
    }
};