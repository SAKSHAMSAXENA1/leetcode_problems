class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),res=INT_MIN;
        vector<vector<int>> maxElement(m,vector<int>(n));

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1) continue;

                if(i+1<m)
                maxElement[i][j]=max({maxElement[i+1][j],grid[i+1][j]});

                if(j+1<n)
                maxElement[i][j]=max({maxElement[i][j],maxElement[i][j+1],grid[i][j+1]});

                res=max(res,maxElement[i][j]-grid[i][j]);
            }
            
        }

        return res;
    }
};