class Solution {
public:
// Memoization
int f(int i,int j,vector<int> &cuts,vector<vector<int>> &dp)
{
    if(i==j-1) // no cut to be made in this piece, therefore no cost incurred from this piece
    return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        int cost=cuts[j]-cuts[i] // cost incurred by cutting this piece
                + f(i,k,cuts,dp) // cost from left piece
                + f(k,j,cuts,dp); // cost from right piece
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        vector<vector<int>> dp(m+2,vector<int>(m+2,-1));

        return f(0,m+1,cuts,dp);
    }
};