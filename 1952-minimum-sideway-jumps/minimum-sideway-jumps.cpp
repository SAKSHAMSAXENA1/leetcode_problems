class Solution {
public:
// Memoization
int f(int index,int lane,vector<int> &obstacles,int &n,vector<vector<int>> &dp)
{
    if(index==n-1) return 0;

    if(dp[index][lane]!=-1) return dp[index][lane];

    if(obstacles[index+1]!=lane)
    return dp[index][lane]=f(index+1,lane,obstacles,n,dp);

    // else jump sideways
    int opt1=INT_MAX,opt2=INT_MAX;
    int nextLane=(lane+1)%3;
    if(obstacles[index]!=nextLane)
    opt1=1+f(index,nextLane,obstacles,n,dp);

    nextLane=(lane+2)%3;
    if(obstacles[index]!=nextLane)
    opt2=1+f(index,nextLane,obstacles,n,dp);

    return dp[index][lane]=min(opt1,opt2);

}
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        for(auto &it:obstacles)
        it--;

        return f(0,1,obstacles,n,dp);
    }
};