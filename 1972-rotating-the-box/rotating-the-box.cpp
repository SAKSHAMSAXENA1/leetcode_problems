class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size(),n=boxGrid[0].size();
        vector<vector<char>> temp(m,vector<char>(n,'.'));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cnt=0;
                while(j<n && boxGrid[i][j]!='*')
                {
                    cnt+=boxGrid[i][j]=='#';
                    j++;
                }

                if(j<n) temp[i][j]='*';
                int start=j-1;
                while(cnt--)
                {
                    temp[i][start--]='#';
                }
            }
        }

        vector<vector<char>> res(n,vector<char>(m));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            res[j][m-1-i]=temp[i][j];
        }

        return res;
    }
};