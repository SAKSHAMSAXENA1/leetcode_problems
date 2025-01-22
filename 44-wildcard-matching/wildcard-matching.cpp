class Solution {
public:
    bool f(int i,int j,string &s,string &p,vector<vector<int>> &dp)
    {
        if(j==0 && i>0) // pattern is empty but still some string is to be matched
        return false; 

        if(i==0) // string to be matched is empty
        {
            while(j>0 && p[j-1]=='*') j--;

            return j==0;
        } 

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==p[j-1]) return dp[i][j]=f(i-1,j-1,s,p,dp);

        // else
        if(p[j-1]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        else if(p[j-1]=='*') return dp[i][j]=f(i-1,j,s,p,dp) || f(i-1,j-1,s,p,dp) || f(i,j-1,s,p,dp);
        // else
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<bool> prev(m+1, false),cur(m+1, false);
        prev[0]=true;

        for(int j=1;j<=m && p[j-1]=='*';j++) prev[j]=true;

        for(int i=1;i<=n;i++)
        {
            cur[0]=false;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1]) cur[j]=prev[j-1];
                else if(p[j-1]=='?') cur[j]=prev[j-1];
                else if(p[j-1]=='*') cur[j]=prev[j] || prev[j-1] || cur[j-1];
                else cur[j]=false;
            }
            prev=cur;
        }

        return prev[m];
    }
};