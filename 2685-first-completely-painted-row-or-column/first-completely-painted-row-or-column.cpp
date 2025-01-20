class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
       int n=mat.size(),m=mat[0].size(),k=arr.size();
       unordered_map<int,int> u; // stores index of each element of matrix
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            u[mat[i][j]]=i*m+j;
        }
       }
       vector<int> row(n,0),col(m,0); 

       for(int i=0;i<k;i++)
       {
        int el=arr[i];
        int elRow=(u[el])/m,elCol=(u[el])%m;
        row[elRow]++;
        if(row[elRow]==m) return i;

        col[elCol]++;
        if(col[elCol]==n) return i;
       }

       return -1;
    }
};