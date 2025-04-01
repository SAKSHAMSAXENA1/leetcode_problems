#define ll long long
class Solution {
public:
ll f(int index,vector<vector<int>> &questions,vector<ll> &dp,int &n)
{
    if(index==n) return 0;

    if(dp[index]!=-1) return dp[index];

    ll take=questions[index][0];
    int nextIndex=index+questions[index][1]+1;
    if(nextIndex<n) 
    take+=f(nextIndex,questions,dp,n);

    ll notTake=f(index+1,questions,dp,n);

    return dp[index]=max(take,notTake);
} 

    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<ll> dp(n+1,-1);
        return f(0,questions,dp,n);
    }
};