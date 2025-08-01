class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows,vector<int>());
        res[0].push_back(1);

        for(int i=1;i<numRows;i++)
        {
            res[i].resize(i+1,0);

            for(int j=0;j<=i;j++)
            {
                if(j-1>=0) res[i][j]+=res[i-1][j-1];

                if(j<i) res[i][j]+=res[i-1][j];
            }
        }

        return res;
    }
};