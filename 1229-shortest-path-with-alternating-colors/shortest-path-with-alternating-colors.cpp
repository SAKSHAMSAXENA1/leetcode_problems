class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adjR(n,vector<int>()),adjB(n,vector<int>());
        vector<int> distR(n,INT_MAX),distB(n,INT_MAX),res(n,-1);

        for(auto it:redEdges)
        {
            int u=it[0],v=it[1];

            //if(u!=v)
            adjR[u].push_back(v);
        }

        for(auto it:blueEdges)
        {
            int u=it[0],v=it[1];

            //if(u!=v)
            adjB[u].push_back(v);
        }

        queue<pair<int,int>> q; // {prevEdge,node} prevEdge:-1:x, 0:red, 1:blue
        q.push({-1,0});
        distR[0]=distB[0]=0;
        int curLevel=0;

        while(!q.empty())
        {
            int levelSize=q.size();

            while(levelSize--)
            {
                int prevEdge=q.front().first,node=q.front().second;
                q.pop();

                if(prevEdge!=0)  // 0 : red
                {
                    for(auto neighbour:adjR[node])
                    {
                        if(curLevel+1<distR[neighbour])
                        {
                            distR[neighbour]=curLevel+1;
                            q.push({0,neighbour});
                        }
                    }
                }

                if(prevEdge!=1)  // 1 : blue
                {
                    for(auto neighbour:adjB[node])
                    {
                        if(curLevel+1<distB[neighbour])
                        {
                            distB[neighbour]=curLevel+1;
                            q.push({1,neighbour});
                        }
                    }
                }
            }

            curLevel++;
        }

        for(int i=0;i<n;i++)
        {
            int minDist=min(distR[i],distB[i]);
            if(minDist!=INT_MAX) 
            res[i]=minDist;
        }

        return res;
    }
};