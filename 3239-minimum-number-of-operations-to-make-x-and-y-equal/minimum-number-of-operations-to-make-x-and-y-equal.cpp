class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_set<int> vis;
        int curLevel=0;
        queue<int> q;
        q.push(x);
        vis.insert(x);

        while(!q.empty())
        {
            int n=q.size();

            while(n--)
            {
                int curx=q.front();
                q.pop();

                if(curx==y) return curLevel;

                if(curx%11==0)
                {
                    int nx=curx/11;
                    if(vis.find(nx)==vis.end())
                    {
                        q.push(nx);
                        vis.insert(nx);
                    }
                }

                if(curx%5==0)
                {
                    int nx=curx/5;
                    if(vis.find(nx)==vis.end())
                    {
                        q.push(nx);
                        vis.insert(nx);
                    }
                }

                int nxDec=curx-1;
                if(vis.find(nxDec)==vis.end())
                {
                    q.push(nxDec);
                    vis.insert(nxDec);
                }

                int nxInc=curx+1;
                if(vis.find(nxInc)==vis.end())
                {
                    q.push(nxInc);
                    vis.insert(nxInc);
                }
            }

            curLevel++;
        }

        return -1;
    }
};