class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m=grid.size(),n=grid[0].size(),k=queries.size(),points=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<pair<int,int>> sortedQ;
        vector<int> res(k);
        int di[]={-1,0,1,0},dj[]={0,1,0,-1};

        for(int i=0;i<k;i++)
        {
            sortedQ.push_back({queries[i],i});
        }

        sort(sortedQ.begin(),sortedQ.end());
           
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=true;

        for(auto &[queryVal,idx]: sortedQ)
        {
            while(!pq.empty() && pq.top().first<queryVal)
            {
                int curi=pq.top().second.first,curj=pq.top().second.second;
                pq.pop();
                points++;

                for(int t=0;t<4;t++)
                {
                    int ni=curi+di[t],nj=curj+dj[t];

                    if(0<=ni && ni<m && 0<=nj && nj<n && !vis[ni][nj])
                    {
                        pq.push({grid[ni][nj],{ni,nj}});
                        vis[ni][nj]=true;
                    }
                }
            }

            res[idx]=points;
        }

        return res;
    }
};