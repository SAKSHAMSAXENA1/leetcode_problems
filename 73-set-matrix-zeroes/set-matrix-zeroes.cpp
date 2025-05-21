class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int m=matrix.size(),n=matrix[0].size();
       vector<bool> zeroRows(m,false),zeroCols(n,false);

       for(int i=0;i<m;i++)
       {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
            {
                zeroRows[i]=zeroCols[j]=true;
            }
        }
       } 

       for(int i=0;i<m;i++)
       {
        if(zeroRows[i]==true) 
        {
            for(int j=0;j<n;j++) matrix[i][j]=0;
        }
       }

       for(int j=0;j<n;j++)
       {
        if(zeroCols[j]==true)
        {
            for(int i=0;i<m;i++) matrix[i][j]=0;
        }
       }
    }
};