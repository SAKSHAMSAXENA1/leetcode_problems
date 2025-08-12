class Solution {
public:
int di[2]={0,1},dj[2]={1,0};
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(),n=coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3)));

        for(int remPower=0;remPower<=2;remPower++)
        dp[m-1][n-1][remPower]=(coins[m-1][n-1]>=0 || remPower==0) ? coins[m-1][n-1] : 0;

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1) continue; // base case already defined

                for(int remPower=0;remPower<=2;remPower++)
                {
                    int usePower=INT_MIN;
                    if(coins[i][j] < 0 && remPower > 0) // robber is present
                    {
                        usePower=0;
                        int maxi=INT_MIN;

                        for(int k=0;k<2;k++)
                        {
                            int ni=i+di[k],nj=j+dj[k];

                            if(0<=ni && ni<m && 0<=nj && nj<n)
                            {
                                maxi=max(maxi,dp[ni][nj][remPower-1]);
                            }
                        }

                        usePower+=maxi;
                    }

                    // robber is not present or I don't have power to avoid robber

                    int powerNotUsed=coins[i][j];
                    int maxi=INT_MIN;

                    for(int k=0;k<2;k++)
                    {
                        int ni=i+di[k],nj=j+dj[k];

                        if(0<=ni && ni<m && 0<=nj && nj<n)
                        {
                            maxi=max(maxi,dp[ni][nj][remPower]);
                        }
                    }

                    powerNotUsed+=maxi;

                    dp[i][j][remPower]=max(usePower,powerNotUsed);
                }
            }
        }
        return dp[0][0][2];
    }
};