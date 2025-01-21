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
        return f(n,m,word1,word2,dp);
    }
};