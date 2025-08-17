class Solution {
public:
int passesDuration[3]={1,7,30};
int upperBound(vector<int> &a,int &n,int &key)
{
    int l=0,h=n-1,res=n;

    while(l<=h)
    {
        int mid=(l+h)/2;

        if(key < a[mid])
        {
            res=mid;
            h=mid-1;
        }
        else l=mid+1;
    }

    return res;
}
// Memoization
int f(int index,vector<int> &days,vector<int> &costs,int &n,vector<int> &dp)
{
    if(index==n) return 0;

    if(dp[index]!=-1) return dp[index];

    int minCost=INT_MAX;
    for(int i=0;i<3;i++)
    {
        int lastDayCovered=days[index]+passesDuration[i]-1;
        int nextDayIndex=upperBound(days,n,lastDayCovered);
        minCost=min(minCost,costs[i]+f(nextDayIndex,days,costs,n,dp));
    }

    return dp[index]=minCost;
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n,-1);
        return f(0,days,costs,n,dp);
    }
};