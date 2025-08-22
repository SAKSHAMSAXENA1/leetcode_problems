class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        int di[2]={-1,1};
        unordered_map<int,vector<int>> indices;
        vector<bool> vis(n,false);

        for(int i=0;i<n;i++)
        indices[arr[i]].push_back(i);

        queue<int> q;
        q.push(0);
        vis[0]=true;
        int curLevel=0;

        // bfs
        while(!q.empty())
        {
            int levelSize=q.size();

            while(levelSize--)
            {
                int cur=q.front();
                q.pop();

                if(cur==n-1) return curLevel;

                for(int k=0;k<2;k++)
                {
                    int ni=cur+di[k];

                    if(0<=ni && ni<n && !vis[ni])
                    {
                        q.push(ni);
                        vis[ni]=true;
                    }
                }

                for(auto ni: indices[arr[cur]])
                {
                    if(!vis[ni])
                    {
                        q.push(ni);
                        vis[ni]=true;
                    }
                }

                indices[arr[cur]].clear();
            }

            curLevel++;
        }

    return -1;
    }
};