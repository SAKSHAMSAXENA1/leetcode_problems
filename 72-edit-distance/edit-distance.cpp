class Solution {
public:
    int f(int i,int j,string &word1, string &word2,vector<vector<int>> &dp)
    {
        if(j==0) return i;

        if(i==0) return j;

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i-1]==word2[j-1]) // match
        return dp[i][j]=f(i-1,j-1,word1,word2,dp);

        // else not match

        int insertCh=f(i,j-1,word1,word2,dp);
        int deleteCh=f(i-1,j,word1,word2,dp);
        int replaceCh=f(i-1,j-1,word1,word2,dp);

        return dp[i][j]=1+min(insertCh,min(deleteCh,replaceCh));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1]) // match
                dp[i][j]=dp[i-1][j-1];

                else// not match
                {
                    int insertCh=dp[i][j-1];
                    int deleteCh=dp[i-1][j];
                    int replaceCh=dp[i-1][j-1];

                    dp[i][j]=1+min(insertCh,min(deleteCh,replaceCh));
                }
            }
        }
        return dp[n][m];
    }
};