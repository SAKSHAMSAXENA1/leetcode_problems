class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum=0,secondRowSum=0,res=LONG_LONG_MAX;
        int n=grid[0].size();

        for(auto it:grid[0])
        firstRowSum+=it;

        for(int i=0;i<n;i++) // i is the turn index of first Robot
        {
            firstRowSum-=grid[0][i];
            res=min(res, max(firstRowSum,secondRowSum));
            secondRowSum+=grid[1][i];
        }

        return res;


    }
};