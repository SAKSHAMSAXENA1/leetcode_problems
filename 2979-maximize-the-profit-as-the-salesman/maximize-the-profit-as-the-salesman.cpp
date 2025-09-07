class Solution {
public:
// Memoization
int ub(vector<vector<int>> &offers,int &curEnd,int &m)
{
    int l=0,h=m-1,res=m;

    while(l<=h)
    {
        int mid=(l+h)/2;

        if(curEnd < offers[mid][0]) // curEnd < start of offers[mid]
        {
            res=mid;
            h=mid-1;
        }
        else l=mid+1;
    }

    return res;
}

int f(int index,vector<vector<int>> &offers,int &m,vector<int> &dp)
{
    if(index==m) return 0;

    if(dp[index]!=-1) return dp[index];

    int nextIndex=ub(offers,offers[index][1],m);
    int take=offers[index][2]+f(nextIndex,offers,m,dp);

    int notTake=f(index+1,offers,m,dp);

    return dp[index]=max(take,notTake);
}
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m=offers.size();
        vector<int> dp(m,-1);
        sort(offers.begin(),offers.end());

        return f(0,offers,m,dp);
    }
};