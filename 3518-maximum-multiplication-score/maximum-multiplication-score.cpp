#define ll long long
class Solution {
public:
ll f(int i,int j,vector<int> &a,vector<int> &b,int &n,vector<vector<ll>> &dp,
vector<vector<bool>> &vis)
{
    if(i==4) return 0;

    if(vis[i][j]==true) return dp[i][j];
    
    // take
    ll take=(ll)a[i]*b[j]+f(i+1,j+1,a,b,n,dp,vis);

    // notTake
    ll notTake=LLONG_MIN;
    if(4-i<n-j)
    notTake=f(i,j+1,a,b,n,dp,vis);

    vis[i][j]=true;
    return dp[i][j]=max(take,notTake);
}
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<vector<ll>> dp(4,vector<ll>(n));
        vector<vector<bool>> vis(4,vector<bool>(n,false));
        return f(0,0,a,b,n,dp,vis);
    }
};