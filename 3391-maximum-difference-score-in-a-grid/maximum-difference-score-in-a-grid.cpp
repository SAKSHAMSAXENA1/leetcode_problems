class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),res=INT_MIN;
        vector<vector<int>> maxElement(m,vector<int>(n));

        maxElement[m-1][n-1]=grid[m-1][n-1];

        for(int j=n-2;j>=0;j--)
        maxElement[m-1][j]=max(maxElement[m-1][j+1],grid[m-1][j+1]);

        for(int i=m-2;i>=0;i--)
        maxElement[i][n-1]=max(maxElement[i+1][n-1],grid[i+1][n-1]);

        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            maxElement[i][j]=max({maxElement[i+1][j],grid[i+1][j],maxElement[i][j+1],grid[i][j+1]});
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==m-1 && j==n-1) continue;

                res=max(res,maxElement[i][j]-grid[i][j]);

            }
        }

        return res;
    }
};