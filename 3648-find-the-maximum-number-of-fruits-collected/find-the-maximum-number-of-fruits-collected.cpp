class Solution {
public:
int f(int startI,int startJ,vector<vector<int>> &fruits,int &n,int factor[],int di[],int dj[])
{
    priority_queue<pair<int,pair<int,int>>> pq;
    vector<vector<int>> dist(n,vector<int>(n,INT_MIN));
    pq.push({0,{startI,startJ}});
    
    while(!pq.empty())
    {
        int curLevelSize=pq.size();
        stack<pair<int,pair<int,int>>> temp;

        while(curLevelSize--)
        {
            int curDist=pq.top().first,i=pq.top().second.first,j=pq.top().second.second;
            pq.pop();

            if(i==n-1 && j==n-1) return dist[i][j];

            for(int k=0;k<3;k++)
            {
                int ni=i+di[k],nj=j+dj[k];
                int remMoves=(n-1-ni)*factor[0]+(n-1-nj)*factor[1];

                if(0<=ni && ni<n && 0<=nj && nj<n && ((n-1-ni)+(n-1-nj))<=2*remMoves)
                {
                    if(curDist+fruits[i][j] > dist[ni][nj])
                    {
                        dist[ni][nj]=curDist+fruits[i][j];
                        temp.push({dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }

        while(!temp.empty())
        {
            pq.push(temp.top());
            temp.pop();
        }
    }

    return -1;
}
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res=0,n=fruits.size();
        int factor1[]={1,0},factor2[]={0,1};
        int di1[]={1,1,1},dj1[]={-1,0,1};
        int di2[]={-1,0,1},dj2[]={1,1,1};

        for(int i=0;i<n;i++)
        {
            res+=fruits[i][i];
            fruits[i][i]=0;
        }

        return res+f(0,n-1,fruits,n,factor1,di1,dj1)+f(n-1,0,fruits,n,factor2,di2,dj2); 
    }
};