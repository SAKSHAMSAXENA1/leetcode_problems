class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m=nums.size();
        vector<int> res;
        int di[2]={1,0},dj[2]={0,1};
        set<pair<int,int>> vis;
        queue<pair<int,int>> q;
        q.push({0,0});
        vis.insert({0,0});

        while(!q.empty())
        {
            int i=q.front().first,j=q.front().second;
            q.pop();

            res.push_back(nums[i][j]);

            for(int k=0;k<2;k++)
            {
                int ni=i+di[k],nj=j+dj[k];

                if(ni<m && nj<nums[ni].size() && vis.find({ni,nj})==vis.end())
                {
                    vis.insert({ni,nj});
                    q.push({ni,nj});
                }
            }
        }

        return res;
    }
};