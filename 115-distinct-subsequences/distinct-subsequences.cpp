class Solution {
public:
    int f(int i,int j, string &s,string &t,vector<vector<int>> &dp)
    {
        if(j==0) return 1;
        if(j>i) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==t[j-1]) // match
        return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
        //else non-match
        return dp[i][j]=f(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        //vector<vector<double>> dp(n+1, vector<double>(m+1,0));
        vector<double> prev(m+1,0),cur(m+1,0);

        prev[0]=cur[0]=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m && j<=i;j++)
            {
                if(s[i-1]==t[j-1]) // match
                cur[j]=prev[j-1]+prev[j];
                else // non-match
                cur[j]=prev[j];
            }
            prev=cur;
        }

        return prev[m];
    }
};