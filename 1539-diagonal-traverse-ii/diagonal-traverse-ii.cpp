class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m=nums.size(),n=0;

        for(int i=0;i<m;i++) n=max(n,(int)nums[i].size());

        vector<int> res;
        int di[2]={1,0},dj[2]={0,1};
        unordered_set<int> vis;
        queue<pair<int,int>> q;
        q.push({0,0});
        vis.insert(0);

        while(!q.empty())
        {
            int i=q.front().first,j=q.front().second;
            q.pop();

            res.push_back(nums[i][j]);

            for(int k=0;k<2;k++)
            {
                int ni=i+di[k],nj=j+dj[k];
                int zeroBasedIndex=ni*n+nj;

                if(ni<m && nj<nums[ni].size() && vis.find(zeroBasedIndex)==vis.end())
                {
                    vis.insert(zeroBasedIndex);
                    q.push({ni,nj});
                }
            }
        }

        return res;
    }
};