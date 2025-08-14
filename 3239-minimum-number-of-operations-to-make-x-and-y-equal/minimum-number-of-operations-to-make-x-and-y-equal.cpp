class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        bool vis[int(1e7)]={false};
        int curLevel=0;
        queue<int> q;
        q.push(x);
        vis[x]=true;

        while(!q.empty())
        {
            int n=q.size();

            while(n--)
            {
                int curx=q.front();
                q.pop();

                if(curx==y) return curLevel;

                if(y < curx)
                {
                    if(curx%11==0)
                    {
                        int nx=curx/11;
                        if(!vis[nx])
                        {
                            q.push(nx);
                            vis[nx]=true;
                        }
                    }

                    if(curx%5==0)
                    {
                        int nx=curx/5;
                        if(!vis[nx])
                        {
                            q.push(nx);
                            vis[nx]=true;
                        }
                    }

                    int nxDec=curx-1;
                    if(!vis[nxDec])
                    {
                        q.push(nxDec);
                        vis[nxDec]=true;
                    }
                }

                int nxInc=curx+1;
                if(!vis[nxInc])
                {
                    q.push(nxInc);
                    vis[nxInc]=true;
                }
            }

            curLevel++;
        }

        return -1;
    }
};