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
        int m=n+2; // new size after padding 1s on extreme left and right
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        // for(int j=1;j<m;j++) dp[j-1][j]=0; // base case-> 0 balloon to burst

    // to have atleast one balloon to burst in the interval, iMAX=n-1, since j>=i+2 and j<=n+1
        // however even if we don't think this deep just start from i=n+1 or n, it will still 
        // work
        for(int i=n-1;i>=0;i--)
        {
            // start from the case just after base case (j=i+1), 
            // i.e j=i+2 onwards (1 balloon to burst)
            for(int j=i+2;j<m;j++)
            {
                int maxi=INT_MIN;
                for(int k=i+1;k<j;k++)
                {
                    int cost=nums[i]*nums[k]*nums[j] // coins collected by bursting this balloon
                                +dp[i][k] // coins collected from left subproblem/interval
                                +dp[k][j]; // coins collected from right subproblem/interval

                     maxi=max(maxi,cost);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[0][n+1];
    }
};