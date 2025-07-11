class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> rowXor(m,vector<int>(n)),colXor(m,vector<int>(n)),
        gridXor(m,vector<int>(n));
        vector<int> xorVal;

        for(int i=0;i<m;i++)
        {
            rowXor[i][0]=matrix[i][0];
            for(int j=1;j<n;j++)
            rowXor[i][j]=rowXor[i][j-1]^matrix[i][j];
        }

        for(int j=0;j<n;j++)
        {
            colXor[0][j]=matrix[0][j];
            for(int i=1;i<m;i++)
            colXor[i][j]=colXor[i-1][j]^matrix[i][j];
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=matrix[i][j];
                if(i>=1 && j>=1) x=x^gridXor[i-1][j-1];
                if(i>=1) x=x^colXor[i-1][j];
                if(j>=1) x=x^rowXor[i][j-1];
                gridXor[i][j]=x;
                xorVal.push_back(x);
            }
        }

        sort(xorVal.rbegin(),xorVal.rend());
        return xorVal[k-1];
    }
};