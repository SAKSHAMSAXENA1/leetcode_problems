class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<priority_queue<int,vector<int>,greater<>>> pq(m+n-1,
        priority_queue<int,vector<int>,greater<>>());
        vector<vector<int>> res(m,vector<int>(n));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>=i) pq[j-i].push(mat[i][j]);
                else pq[n+i-j-1].push(mat[i][j]);
            }
        } 

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>=i)
                {
                    res[i][j]=(pq[j-i].top());
                    pq[j-i].pop();
                }
                else 
                {
                    res[i][j]=(pq[n+i-j-1].top());
                    pq[n+i-j-1].pop();
                }
            }
        }

        return res;
    }
};