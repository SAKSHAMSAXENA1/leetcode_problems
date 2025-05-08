class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        int di[]={-1,0,1,0},dj[]={0,1,0,-1};
        int n=moveTime.size(),m=moveTime[0].size();
        vector<vector<int>> visitTime(n,vector<int>(m,INT_MAX));
        vector<vector<bool>> toggle(n,vector<bool>(m,false)); // f=1,t=2
        pq.push({0,{0,0}}); // {curTime,{i,j}}
        visitTime[0][0]=0;

        while(!pq.empty())
        {
            int curTime=pq.top().first;
            int i=pq.top().second.first,j=pq.top().second.second;
            pq.pop();

            for(int k=0;k<4;k++)
            {
                int ni=i+di[k],nj=j+dj[k];

                if(0<=ni && ni<n && 0<=nj && nj<m)
                {
                    int departTime=max(curTime,moveTime[ni][nj]); // depart from (i,j)
                    int arrivalTime=departTime+((toggle[i][j]) ? 2:1); // arrive at (ni,nj)

                    if(arrivalTime<visitTime[ni][nj])
                    {
                        if(ni==n-1 && nj==m-1) return arrivalTime;
                        visitTime[ni][nj]=arrivalTime;
                        toggle[ni][nj]=!toggle[i][j];
                        pq.push({arrivalTime,{ni,nj}});
                    }
                }
            }
        }

        return -1;
    }
};