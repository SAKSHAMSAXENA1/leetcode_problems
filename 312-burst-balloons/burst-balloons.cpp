class Solution {
public:
int f(int i,int j,vector<int> &nums,vector<vector<int>> &dp)
{
    if(i==j-1) return 0; // no balloon to burst in this interval, we just have padding values at
    // i and j

    if(dp[i][j]!=-1) return dp[i][j];
    int maxi=INT_MIN;
    for(int k=i+1;k<j;k++)
    {
        int cost=nums[i]*nums[k]*nums[j] // coins collected by bursting this balloon
                +f(i,k,nums,dp) // coins collected from left subproblem/interval
                +f(k,j,nums,dp); // coins collected from right subproblem/interval

        maxi=max(maxi,cost);
    }

    return dp[i][j]=maxi;
}
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1); // padding
        nums.push_back(1); // padding
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return f(0,n+1,nums,dp);
    }
};