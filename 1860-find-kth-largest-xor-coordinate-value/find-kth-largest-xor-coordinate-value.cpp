class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> rowXor(m,vector<int>(n)),colXor(m,vector<int>(n)),
        gridXor(m,vector<int>(n));
        gridXor[0][0]=matrix[0][0];
        vector<int> xorVal;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0) colXor[i][j]=matrix[i][j];
                if(j==0) rowXor[i][j]=matrix[i][j];
                
                gridXor[i][j]=matrix[i][j];
                if(i>=1 && j>=1) gridXor[i][j]=gridXor[i][j]^gridXor[i-1][j-1];

                if(i>=1)
                {
                    gridXor[i][j]=gridXor[i][j]^colXor[i-1][j];
                    colXor[i][j]=colXor[i-1][j]^matrix[i][j];
                }

                if(j>=1) 
                {
                    gridXor[i][j]=gridXor[i][j]^rowXor[i][j-1];
                    rowXor[i][j]=rowXor[i][j-1]^matrix[i][j];
                }

                xorVal.push_back(gridXor[i][j]);
            }
        }

        sort(xorVal.rbegin(),xorVal.rend());
        return xorVal[k-1];
    }
};