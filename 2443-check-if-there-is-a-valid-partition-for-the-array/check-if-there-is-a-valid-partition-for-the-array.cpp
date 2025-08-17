class Solution {
public:
/*
// Memoization
bool f(int index,vector<int> &nums,int &n,vector<int> &dp)
{
    if(index==n) return true;

    if(dp[index]!=-1) return dp[index];

    bool opt1=false,opt2=false,opt3=false;
    if(index+1<n && nums[index]==nums[index+1])
    opt1=f(index+2,nums,n,dp);

    if(index+2<n)
    {
        if(nums[index]==nums[index+1] && nums[index+1]==nums[index+2])
        opt2=f(index+3,nums,n,dp);

        if(nums[index]+1==nums[index+1] && nums[index+1]+1==nums[index+2])
        opt3=f(index+3,nums,n,dp);
    }

    return dp[index]=opt1 || opt2 || opt3;
}
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,n,dp);
    }*/

// Tabulation
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n+1,true);

        for(int index=n-1;index>=0;index--)
        {
            bool opt1=false,opt2=false,opt3=false;
            if(index+1<n && nums[index]==nums[index+1])
            opt1=dp[index+2];

            if(index+2<n)
            {
                if(nums[index]==nums[index+1] && nums[index+1]==nums[index+2])
                opt2=dp[index+3];

                if(nums[index]+1==nums[index+1] && nums[index+1]+1==nums[index+2])
                opt3=dp[index+3];
            }

            dp[index]=opt1 || opt2 || opt3;
        }
        
        return dp[0];
    }
};