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
                int x=matrix[i][j];
                if(i>=1 && j>=1) x=x^gridXor[i-1][j-1];
                if(i>=1)
                {
                    x=x^colXor[i-1][j];
                    colXor[i][j]=colXor[i-1][j]^matrix[i][j];
                }
                if(j>=1) 
                {
                    x=x^rowXor[i][j-1];
                    rowXor[i][j]=rowXor[i][j-1]^matrix[i][j];
                }
                gridXor[i][j]=x;
                xorVal.push_back(x);
            }
        }

        sort(xorVal.rbegin(),xorVal.rend());
        return xorVal[k-1];
    }
};