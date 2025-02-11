class Solution {
public:
bool isValid(int &i,int &j,int &rows,int &columns)
{
    return 0<=i && i<rows && 0<=j && j<columns;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size(),columns=heights[0].size();
        vector<vector<int>> pathEffort(rows,vector<int> (columns,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({0,{0,0}});
        pathEffort[0][0]=0;
        int di[]={-1,0,1,0},dj[]={0,1,0,-1};

        while(!pq.empty())
        {
            int curEffort=pq.top().first;
            int curi=pq.top().second.first,curj=pq.top().second.second;
            pq.pop();

            for(int k=0;k<4;k++)
            {
                int ni=curi+di[k],nj=curj+dj[k];

                if(isValid(ni,nj,rows,columns))
                {
                    int nextEffort=abs(heights[curi][curj]-heights[ni][nj]);
                    int maxEffort=max(nextEffort,curEffort);

                    if(maxEffort<pathEffort[ni][nj])
                    {
                        pathEffort[ni][nj]=maxEffort;

                        if(!(ni==rows-1 && nj==columns-1))
                        pq.push({pathEffort[ni][nj],{ni,nj}});
                    }
                }
            }
        }
    return pathEffort[rows-1][columns-1];
    }
};