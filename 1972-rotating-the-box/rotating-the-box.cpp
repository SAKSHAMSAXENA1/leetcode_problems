class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size(),n=boxGrid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cnt=0;
                while(j<n && boxGrid[i][j]!='*')
                {
                    if(boxGrid[i][j]=='#') cnt++;
                    else swap(boxGrid[i][j],boxGrid[i][j-cnt]);
                    j++;
                }
            }
        }

        vector<vector<char>> res(n,vector<char>(m));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            res[j][m-1-i]=boxGrid[i][j];
        }

        return res;
    }
};