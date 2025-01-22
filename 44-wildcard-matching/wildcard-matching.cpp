class Solution {
public:
    bool f(int i,int j,string &s,string &p,vector<vector<int>> &dp)
    {
        if(j==0 && i>0) // pattern is empty but still some string is to be matched
        return false; 

        if(i==0) // string to be matched is empty
        {
            //return j==0; // return true if pattern to be matched is also empty, false otherwise
            if(j==0) return true; // return true if pattern to be matched is also empty
            else //return p[0]=='*' && j==1; // return true if p[0]=='*', false otherwise
            {
                while(j>0 && p[j-1]=='*') j--;

                return j==0;
            }
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
        vector<vector<int>> dp(n+1,vector<int> (m+1, -1));
        return f(n,m,s,p,dp);
    }
};