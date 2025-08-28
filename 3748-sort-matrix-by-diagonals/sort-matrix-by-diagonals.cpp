class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> res(n,vector<int>(n));

        for(int col=n-1;col>0;col--)
        {
            vector<int> temp;
            int i=0,j=col,k=0;

            while(j<n)
            {
                temp.push_back(grid[i][j]);
                j++;
                i++;
            }

            sort(temp.begin(),temp.end());

            i=0;j=col;
            while(j<n)
            {
                res[i][j]=temp[k];
                i++;j++;
                k++;
            }
        }

        for(int row=0;row<n;row++)
        {
            int i=row,j=0,k=0;
            vector<int> temp;

            while(i<n)
            {
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }

            sort(temp.begin(),temp.end(),greater<>());

            i=row;j=0;
            while(i<n)
            {
                res[i][j]=temp[k];
                i++;j++;
                k++;
            }
        }

        return res;
    }
};