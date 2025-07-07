class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int>res;
        vector<vector<int>> adj(n+1,vector<int>());

        for(int i=1;i<=n;i++)
        {
            if(i+1<=n) adj[i].push_back(i+1);
            if(i-1>=1) adj[i].push_back(i-1);
        }

        adj[x].push_back(y);
        adj[y].push_back(x);

        for(int k=1;k<=n;k++)
        {
            int pairs=0;
            for(int i=1;i<=n;i++)
            {
                vector<bool> vis(n+1,false);
                queue<int> q;
                q.push(i);
                vis[i]=true;
                int curLevel=0;

                while(!q.empty() && curLevel<k)
                {
                    int m=q.size();

                    while(m--)
                    {
                        int curNode=q.front();
                        q.pop();

                        for(auto neighbour:adj[curNode])
                        {
                            if(!vis[neighbour])
                            {
                                vis[neighbour]=true;
                                q.push(neighbour);
                            }
                        }
                    }

                    curLevel++;
                }

                pairs+=q.size();
            }
            res.push_back(pairs);
        }

        return res;
    }
};