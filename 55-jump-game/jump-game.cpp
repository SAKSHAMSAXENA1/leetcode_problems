class Solution {
public:
/* // Memoization
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
}*/
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,false);

        dp[n-1]=true;

        for(int index=n-2;index>=0;index--)
        {
            for(int jump=1;jump<=nums[index] && index+jump<n;jump++)
            {
                if(dp[index+jump]==true)
                {
                    dp[index]=true;
                    break;
                }
            }
        }

        return dp[0];
    }
};