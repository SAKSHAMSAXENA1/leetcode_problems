class Solution {
public:
/* // Memoization
int f(int index,int prevParity,int flip,vector<int> &nums,int &n,
vector<vector<vector<int>>> &dp)
{
    if(index==n) return 0;

    if(dp[index][prevParity][flip]!=-1) return dp[index][prevParity][flip];

    int curParity=nums[index]%2;

    int take=INT_MIN;
    // take
    if(flip==2) // flip not set yet
    {
        int temp1=1+f(index+1,curParity,1,nums,n,dp); // next element of opposite parity
        int temp2=1+f(index+1,curParity,0,nums,n,dp); // next element of same parity
        take=max(temp1,temp2);
    }
    else if(flip==0) // curParity should be same as prevParity
    {
        if(curParity==prevParity)
        take=1+f(index+1,curParity,0,nums,n,dp);
    }
    else // if(flip==1) // curParity should be opposite of prevParity
    {
        if(curParity!=prevParity)
        take=1+f(index+1,curParity,1,nums,n,dp);
    }

    // not take
    int notTake=f(index+1,prevParity,flip,nums,n,dp);

    return dp[index][prevParity][flip]=max(take,notTake);
}*/
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(3,0)));

        for(int index=n-1;index>=0;index--)
        {
            for(int prevParity=0;prevParity<=2;prevParity++)
            {
                for(int flip=0;flip<=2;flip++)
                {
                    int curParity=nums[index]%2;

                    int take=INT_MIN;
                    // take
                    if(flip==2) // flip not set yet
                    {
                        int temp1=1+dp[index+1][curParity][1]; // next element of opposite parity
                        int temp2=1+dp[index+1][curParity][0]; // next element of same parity
                        take=max(temp1,temp2);
                    }
                    else if(flip==0) // curParity should be same as prevParity
                    {
                        if(curParity==prevParity)
                        take=1+dp[index+1][curParity][0];
                    }
                    else // if(flip==1) // curParity should be opposite of prevParity
                    {
                        if(curParity!=prevParity)
                        take=1+dp[index+1][curParity][1];
                    }

                    // not take
                    int notTake=dp[index+1][prevParity][flip];

                    dp[index][prevParity][flip]=max(take,notTake);
                }
            }
        }
        //return f(0,2,2,nums,n,dp);
        return dp[0][2][2];
    }
};